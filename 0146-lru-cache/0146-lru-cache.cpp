struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }

    Node() {
        next = nullptr;
        prev = nullptr;
        key = 0;
        value = 0;
    }
};

class LRUCache {
    unordered_map<int, Node*> mp;
    Node* closet;
    Node* furthest;
    int cap;

public:
    LRUCache(int capacity) {
        furthest = new Node(0, 0);
        closet = new Node(0, 0);
        furthest->next = closet;
        closet->prev = furthest;
        cap = capacity;
    }

    void deleteNode(Node* cur) {
        Node* after = cur->next;
        Node* before = cur->prev;
        after->prev = before;
        before->next = after;
    }

    void addNode(Node* cur) {
        Node* before = closet->prev;
        cur->next = closet;
        cur->prev = before;
        before->next = cur;
        closet->prev = cur;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* res = mp[key];
        int ans = res->value;
        deleteNode(res);
        addNode(res);
        mp.erase(key);
        mp[key] = closet->prev;
        return ans;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* res = mp[key];
            mp.erase(key);
            deleteNode(res);
        }

        if (mp.size() == cap) {
            Node* lru = furthest -> next;
            int key = lru -> key;
            mp.erase(key);
            deleteNode(lru);
            delete lru;
        }

        addNode(new Node(key, value));
        mp[key] = closet->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */