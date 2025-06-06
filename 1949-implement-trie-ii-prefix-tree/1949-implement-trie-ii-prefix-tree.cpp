class TrieNode {
public:
    vector<TrieNode*> child;
    int wordCount;
    int prefixCount;

    TrieNode(){
        child = vector<TrieNode*>(26, NULL);
        prefixCount = 0;
        wordCount = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(!cur -> child[c - 'a']){
                TrieNode* newNode = new TrieNode();
                cur -> child[c - 'a'] = newNode;
            }
            cur = cur -> child[c - 'a'];
            cur -> prefixCount += 1;
        }
        cur -> wordCount += 1;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* cur = root;
        for(auto c : word){
            if(!cur -> child[c - 'a']){
                return 0;
            }
            cur = cur -> child[c - 'a'];
        }
        return cur -> wordCount;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* cur = root;
        for(auto c : prefix){
            if(!cur -> child[ c - 'a'])
                return 0;
            cur = cur -> child[c - 'a'];
        }
        return cur -> prefixCount;
    }
    
    void erase(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(!cur -> child[c - 'a']){
                return;
            }
            TrieNode* next = cur -> child[c - 'a'];
            next -> prefixCount -= 1;
            if(next -> prefixCount == 0){
                delete next;
                cur -> child[c - 'a'] = nullptr;
                return;
            }
            cur = next;
        }
        cur -> wordCount -= 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */