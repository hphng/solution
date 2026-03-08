class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();

        grid[x][y] = '0';

        vector<int> dir = {1, 0, -1, 0, 1};
        for(int i = 0; i < 4; i++){
            int newX = x + dir[i];
            int newY = y + dir[i+1];

            if(newX < 0 || newY < 0 || newX >= n || newY >= m || grid[newX][newY] != '1'){
                continue;
            }
            dfs(grid, newX, newY);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};