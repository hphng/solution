struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(): key(-1), value(-1), prev(nullptr), next(nullptr) {}
    Node(int key, int value): key(key), value(value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> mp; //mp[key] = value
    Node* head;
    Node* tail;
    int capacity;

    void insertNode(Node* node){
        Node* prevNode = tail -> prev;

        prevNode -> next = node;
        node -> prev = prevNode;

        node -> next = tail;
        tail -> prev = node;
    }

    void deleteNode(Node* node){
        Node* left = node -> prev;
        Node* right = node -> next;
        left -> next = right;
        right -> prev = left;
    }

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node();
        tail = new Node();
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            Node* cur = mp[key];
            deleteNode(cur);
            insertNode(cur);
            return cur -> value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            deleteNode(mp[key]);
        }

        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        insertNode(newNode);

        if(mp.size() > capacity) {
            Node* old = head -> next;
            deleteNode(old);
            mp.erase(old -> key);
            delete old;
        }
    }

    // ~LRUCache() {
    //     Node* cur = head;
    //     while(cur) {
    //         Node* next = cur -> next;
    //         delete cur;
    //         cur = next;
    //     }
    // }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */