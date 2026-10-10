class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        //check current row is safe or not
        vector<vector<int>> dirs = {
            {1, 0}, {0, 1}, {1, -1}, {1, 1},
            {-1, 0}, {0, -1}, {-1, 1}, {-1, -1}
        };

        int n = board.size();
        for(const auto d: dirs) {
            int newRow = row + d[0];
            int newCol = col + d[1];

            while(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                if(board[newRow][newCol] == 'Q') {
                    return false;
                }
                newRow += d[0];
                newCol += d[1];
            }
        }
        return true;
    }

    void backtrack(vector<vector<string>>& ans, vector<string>& cur, int index) {
        int n = cur.size();
        if(index == n) {
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(isSafe(cur, i, index)) {
                cur[i][index] = 'Q';
                backtrack(ans, cur, index + 1);
                cur[i][index] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        backtrack(ans, board, 0);
        return ans; 
    }
};