class Solution {
public:
    const int SUM = 15;
    bool isMagicSquare(vector<vector<int>>& grid, int n, int m) {
        unordered_set<int> unique;
        // check for unique and from 1 -> 9
        for (int i = n - 2; i <= n; i++) {
            for (int j = m - 2; j <= m; j++) {
                if(grid[i][j] > 9 || grid[i][j] < 1){
                    return false;
                }

                if (unique.contains(grid[i][j])) { 
                    return false; 
                }
                unique.insert(grid[i][j]);
            }
        }
        //column
        for (int i = n - 2; i <= n; i++) {
            int sum = 0;
            for (int j = m - 2; j <= m; j++) {
                sum += grid[i][j];
            }
            if (sum != SUM) {
                return false;
            }
        }
        //row
        for(int j = m-2; j <= m; j++){
            int sum = 0;
            for(int i = n-2; i <= n; i++){
                sum += grid[i][j];
            }
            if(sum != SUM) {
                return false;
            }
        }

        int d1 = grid[n-2][m-2] + grid[n-1][m-1] + grid[n][m];
        int d2 = grid[n-2][m] + grid[n-1][m-1] + grid[n][m-2];
        if(d1 != SUM || d2 != SUM){
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++) {
                if(isMagicSquare(grid, i, j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};