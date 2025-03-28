class Solution {
public:
    bool isSafe (vector<string>& NQueens, int row, int col){
        int n = NQueens.size();
        for(int i = 0; i < n; i++){
            if(NQueens[i][col] == 'Q'){
                return false;
            }
        }

        // for(int i = 0; i < n; i++){
        //     if(NQueens[row][i] == 'Q'){
        //         return false;
        //     }
        // }

        for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--){
            if(NQueens[i][j] == 'Q'){
                return false;
            }
        }

        for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++){
            if(NQueens[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void backtrack(vector<vector<string>>& ans, vector<string>& NQueens, int row){
        int n = NQueens.size();
        if(row == n){
            ans.push_back(NQueens);
            return;
        }
        for(int col = 0; col < n; col++){
            if(isSafe(NQueens, row, col)){
                NQueens[row][col] = 'Q';
                backtrack(ans, NQueens, row+1);
                NQueens[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> NQueens(n, string(n, '.'));
        backtrack(ans, NQueens, 0);
        return ans;
    }
};