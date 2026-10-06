class LRUCache {
private:
    int CAP;
    int currentLength;
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int key, int value): key(key), value(value) {
            next = nullptr;
            prev = nullptr;
        }
    };

    unordered_map<int, Node*> mp; // value: Node
    Node* head;
    Node* tail;

    void addNode(int key, int value) {
        Node* cur = new Node(key, value);

        Node* latest = tail -> prev;

        latest -> next = cur;
        cur -> prev = latest;

        cur -> next = tail;
        tail -> prev = cur;
        mp[key] = cur;
        currentLength++;
    }

    void deleteNode(Node* cur) {
        //delete cur in this position
        cur -> prev -> next = cur -> next;
        cur -> next -> prev = cur -> prev;

        mp.erase(cur-> key);
        delete cur;
        currentLength--;
    }
public:
    LRUCache(int capacity): CAP(capacity), currentLength(0) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        int value = mp[key] -> value;
        deleteNode(mp[key]);
        addNode(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* cur = mp[key];
            deleteNode(cur);
            addNode(key, value);
            return;
        }

        if(currentLength == CAP) {
            deleteNode(head -> next);
        }

        addNode(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */