struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp; // key , node of key, value
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void remove(Node* node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    void add(Node* node){
        Node* nPrev = tail -> prev;
        nPrev -> next = node;
        node -> next = tail;
        tail -> prev = node;
        node -> prev = nPrev;
    }
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        remove(mp[key]);
        add(mp[key]);
        int val = mp[key] -> val;
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* cur = mp[key];
            remove(cur);
            mp.erase(key);
            delete cur;
            Node* node = new Node(key, value);
            add(node);
            mp[key] = node;
        } else {
            if(mp.size() == cap){
                Node* del = head -> next;
                remove(del);
                mp.erase(del -> key);
                delete del;
            }
            Node *node = new Node(key, value);
            add(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */