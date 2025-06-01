class Solution {
public:
    bool backtrack(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, string& word, int wordIndex){
        if(word.size() == wordIndex){
            return true;
        }
        int n = board.size();
        int m = board[0].size();
        if( i >= n || i < 0 || j >= m || j < 0 || visited[i][j]){
            return false;
        }
        // cout << i << " " << j << endl;
        // cout << word[wordIndex] << " " << board[i][j] << endl;
        if(word[wordIndex] != board[i][j]){
            return false;
        }
        visited[i][j] = true;

        vector<int> dir = {1, 0, -1, 0, 1};
        for(int k = 0; k < 4; k++){
            int newi = i + dir[k];
            int newj = j + dir[k+1];
            int check = backtrack(board, newi, newj, visited, word, wordIndex+1);
            if(check){
                return true;
            }
        }

        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(auto& row : board){
            for(char c : row){
                mp1[c]++;
            }
        }

        for(char c : word){
            mp2[c]++;
            if(mp2[c] > mp1[c]){
                return false;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(backtrack(board, i, j, visited, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};