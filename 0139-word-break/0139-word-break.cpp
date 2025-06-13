class TrieNode {
public:
    vector<TrieNode*> child;
    bool isLeaf;

    TrieNode(){
        child = vector<TrieNode*> (26, NULL);
        isLeaf = false;
    } 
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }

    void addWord(string word){
        TrieNode* cur = root;
        for(char c : word){
            if(!cur-> child[c - 'a']){
                cur -> child[c - 'a'] = new TrieNode();
            }
            cur = cur -> child[c - 'a'];
        }
        cur -> isLeaf = true;
    }

    bool checkLeaf(string word, int start, int end){
        TrieNode* cur = root;
        for(int i = start; i < end; i++){
            char c = word[i];
            if(!cur-> child[c - 'a']){
                return false;
            }
            cur = cur -> child[c - 'a'];
        }
        return cur -> isLeaf;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_map<int, vector<string>> mp; //store word with their length
        for(string word: wordDict){
            int x = word.length();
            mp[x].push_back(word);
        }

        vector<bool> ans(n+1, false); //dp from top to bottom
        ans[0] = true;

        vector<int> leaf; //index that is a leaf
        leaf.push_back(0);

        Trie tree; //trie node to check leaf or not
        for(string word: wordDict){
            tree.addWord(word);
        }
        //dp
        for(int i = 1; i < ans.size(); i++){
            for(int j = 0; j < i; j++){
                if(ans[j] && tree.checkLeaf(s, j, i)){
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans[n];
    }
};