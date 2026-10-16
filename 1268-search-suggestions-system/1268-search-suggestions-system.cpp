class Solution {
private:
    struct TrieNode {
        vector<TrieNode*> child;
        priority_queue<string, vector<string>, greater<string>> words;

        TrieNode() {
            child.resize(26, nullptr);
        }
    };

    TrieNode* root;

    void addWord(const string word) {
        TrieNode* node = root;

        for(const auto c: word) {
            if(!node -> child[c-'a']) {
                node -> child[c-'a'] = new TrieNode();
            }
            node = node -> child[c-'a'];
            node -> words.push(word);
        }
    }


public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        root = new TrieNode();

        for(const string& word: products) {
            addWord(word);
        }

        TrieNode* node = root;
        for(const auto& c: searchWord) {
            vector<string> cur;
            if(node) {
                node = node -> child[c-'a'];
            }

            if(!node) {
                ans.push_back(cur);
                continue;
            }

            int count = 3;
            while(!node -> words.empty() && count > 0) {
                cur.push_back(node -> words.top());
                node -> words.pop();
                count--;
            }

            ans.push_back(cur);
        }
        return ans;        
    }
};