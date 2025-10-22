struct TrieNode {
    vector<TrieNode*> children;
    bool isWord;
    string word;

    TrieNode() {
        children.resize(26, nullptr);
        isWord = false;
        word = "";
    }
};

class Solution {
public:
    void insert(TrieNode* root, string word){
        TrieNode* node = root;
        for(char c: word){
            if(node -> children[c - 'a'] == nullptr){
                node -> children[c-'a'] = new TrieNode();
            }
            node = node -> children[c-'a'];
        }
        node -> isWord = true;
        node -> word = word;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int i, int j, vector<string>& result){
        char c = board[i][j];
        TrieNode* node = root;
        if(c == '#' || node->children[c - 'a'] == nullptr){
            return;
        }
        node = node -> children[c -'a'];
        if(node -> isWord){
            result.push_back(node -> word);
            node -> isWord = false;
        }
        board[i][j] = '#';
        int m = board.size();
        int n = board[0].size();

        vector<int> direction = {1, 0, -1, 0, 1};
        for(int t = 0; t < 4; t++){
            int x = i + direction[t];
            int y = j + direction[t+1];

            if(x < 0 || y < 0 || x >= m || y >= n){
                continue;
            }

            dfs(board, node, x, y, result);
        }
        board[i][j] = c;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        TrieNode* node = root;

        for(auto word: words){
            insert(root, word);
        }

        int m = board.size();
        int n = board[0].size();
        vector<string> ans;
        string cur = "";
        vector<string> result;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, root, i, j, result);
            }
        }
        return result;
    }
};