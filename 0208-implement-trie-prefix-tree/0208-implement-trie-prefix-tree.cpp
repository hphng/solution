
class Trie {
private:
    struct TrieNode {
        vector<TrieNode*> child;
        bool isWord;

        TrieNode(): isWord(false)  {
            child.resize(26, nullptr);
        }
    };
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node -> child[word[i]-'a'])
                node -> child[word[i] - 'a'] = new TrieNode();
            node = node -> child[word[i] - 'a'];
        }
        node -> isWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); i++) {
            char c = word[i];
            if(!node -> child[c-'a']) {
                return false;
            }
            node = node -> child[c-'a'];
        }

        return node -> isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i = 0; i < prefix.length(); i++){
            char c = prefix[i];
            if(!node -> child[c-'a']){
                return false;
            }
            node = node -> child[c-'a'];
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