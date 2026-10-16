class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    count++;
                }
            }
        }
        vector<int> dirs = {1, 0, -1, 0, 1};
        int time = 0;
        while(!q.empty()&& count > 0) {
            int size = q.size();
            for(int s = 0; s < size; s++) {
                auto [row, col] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nr = row + dirs[i];
                    int nc = col + dirs[i+1];

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 1) {
                        continue;
                    }

                    q.push({nr, nc});
                    count--;
                    grid[nr][nc]= 2;
                }
            }
            time++;
        }

        if(count > 0) return -1;
        return time;

    }
};