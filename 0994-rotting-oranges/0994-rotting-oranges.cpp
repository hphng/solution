class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }

                if(grid[i][j] == 1){
                    fresh++;
                }

            } 
        }

        if(fresh == 0) {
            return 0;
        }

        vector<int> dir = {1, 0, -1, 0, 1};
        int time = 0;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto [x, y] = q.front();
                q.pop();

                for(int t = 0; t < 4; t ++) {
                    int newX = x + dir[t];
                    int newY = y + dir[t+1];


                    if(newX < 0 || newY < 0 || newX >= n || newY >=m){
                        continue;
                    }

                    if(grid[newX][newY] == 1) {
                        q.push({newX, newY});
                        grid[newX][newY] = 2;
                        fresh--;
                    }
                }
            }
            time++;
        }

        if(fresh != 0) return -1;
        return time-1;
    }
};