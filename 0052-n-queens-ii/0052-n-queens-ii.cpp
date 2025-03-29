class Solution {
public:
    bool isSafe (vector<string> Nqueens, int row, int col){
        int n = Nqueens.size();
        for(int i = 0; i < n; i++){
            if(Nqueens[i][col] == 'Q'){
                return false;
            }
        }

        for(int i = row-1, j = col-1; i >=0 && j >=0; i--, j--){
            if(Nqueens[i][j] == 'Q'){
                return false;
            }
        }

        for(int i = row-1, j = col+1; i >= 0 && j <n ; i--, j++){
            if(Nqueens[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void backtrack(int& ans, vector<string>& Nqueens, int row){
        int n = Nqueens.size();
        if(row == n){
            ans++;
            return;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(Nqueens, row, col)){
                Nqueens[row][col] = 'Q';
                backtrack(ans, Nqueens, row+1);
                Nqueens[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> Nqueens (n, string(n, '.'));
        int ans = 0;
        backtrack(ans, Nqueens, 0);
        return ans;
    }
};