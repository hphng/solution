struct Node {
    int key;
    int val;
    int freq;
    Node* next;
    Node* prev;

    Node(int key, int val): key(key), val(val), freq(1), next(nullptr), prev(nullptr) {}
};

class DLL {
    int size_;
public:
    Node* head; //first node inserted
    Node* tail; //latest node inserted
    DLL(): size_(0) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node* node) {
        Node* latest = tail -> prev;
        latest -> next = node;
        node -> prev = latest;

        node -> next = tail;
        tail -> prev = node;
        size_++;
    }

    void removeNode(Node* node) {
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;

        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
        size_--;
    }

    int size() {
        return size_;
    }
};

class LFUCache {
private:
    int minFreq_;
    int currentCapacity_;
    int maxCapacity_;
    unordered_map<int, Node*> mapping_;
    unordered_map<int, DLL*> mp_; //freq: DLL

    DLL* list(int freq) {
        if(mp_.find(freq) == mp_.end()) {
            mp_[freq] = new DLL();
        }
        return mp_[freq];
    }

    void touch(Node* node) {
        int freq = node -> freq;
        mp_[freq] -> removeNode(node);

        if(freq == minFreq_ && mp_[freq] -> size() == 0) {
            minFreq_++;
        }

        node-> freq++;
        list(node-> freq) -> addNode(node);
    }

public:
    LFUCache(int capacity): maxCapacity_(capacity), minFreq_(0), currentCapacity_(0) {
        
    }
    
    int get(int key) {
        if(mapping_.find(key) == mapping_.end()) {
            return -1;
        }

        Node* cur = mapping_[key];
        touch(cur);
        return cur -> val;
    }
    
    void put(int key, int value) {
        if(mapping_.find(key) != mapping_.end()) {
            Node* node = mapping_[key];
            node -> val = value;
            touch(node);
            return;
        }

        //insert new node
        if(currentCapacity_ == maxCapacity_) {
            DLL* llist = mp_[minFreq_];
            Node* victim = llist -> head -> next;
            llist -> removeNode(victim);
            mapping_.erase(victim -> key);
            delete victim;
            currentCapacity_--;
        }

        Node* cur = new Node(key, value);
        list(1) -> addNode(cur);
        mapping_[key] = cur;
        minFreq_ = 1;
        currentCapacity_++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */