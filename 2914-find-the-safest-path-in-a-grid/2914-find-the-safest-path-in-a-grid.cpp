class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        vector<vector<int>> bfs(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    bfs[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }

        vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto dir:direction){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX < 0 || newY < 0 || newX >=n || newY >=n){
                    continue;
                }

                if(visited[newX][newY]){
                    continue;
                }

                bfs[newX][newY] = min(bfs[newX][newY], bfs[x][y]+1);
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << bfs[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        //djikstra
        priority_queue<pair<int, pair<int, int>>> pq;

        pq.push({bfs[0][0], {0, 0}});

        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][0] = bfs[0][0];

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int curDistance = top.first;
            auto [x, y] = top.second;

            if(dist[x][y] < curDistance){
                continue;
            }

            for(int i = 0; i < direction.size(); i++){
                int newX = x + direction[i].first;
                int newY = y + direction[i].second;
                if(newX < 0 || newY < 0 || newX >= n || newY >= n){
                    continue;
                }
                int newDistance = min(curDistance, bfs[newX][newY]);
                if(newDistance > dist[newX][newY]){
                    dist[newX][newY] = newDistance;
                    pq.push({dist[newX][newY], {newX, newY}});
                }
            }
        }
        return dist[n-1][n-1];
    }
};