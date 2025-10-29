class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        //dijkstra
        priority_queue<tuple<int, int, int>> pq;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n , INT_MIN));
        pq.push({grid[0][0], 0, 0});
        vector<int> direction = {1, 0, -1, 0, 1};
        while(!pq.empty()){
            auto[curScore, x, y] = pq.top();
            pq.pop();
            
            for(int i = 0; i < 4; i++){
                int newX = x + direction[i];
                int newY = y + direction[i+1];
                if(newX < 0 || newY < 0 || newX >= m || newY >= n){
                    continue;
                }

                int newScore = min(grid[newX][newY], curScore);
                if(newScore > dist[newX][newY]){
                    dist[newX][newY] = newScore;
                    pq.push({dist[newX][newY], newX, newY});
                }
            }
        }

        return dist[m-1][n-1];

    }
};