class TrieNode {
public:
    TrieNode* child[26];
    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr -> child[c - 'a']){
                TrieNode* newNode = new TrieNode();
                curr -> child[c - 'a'] = newNode;
            }
            curr = curr -> child[c -'a'];
        }
        curr -> isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c: word){
            if(!curr -> child[c - 'a']){
                return false;
            }
            curr = curr -> child[c -'a'];
        }
        return curr -> isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if(!curr -> child[c - 'a']){
                return false;
            }
            curr = curr -> child[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */