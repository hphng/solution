class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        vector<int> dir = {1, 0, -1, 0, 1};
        while(!pq.empty()){
            auto [h, x, y] = pq.top();
            pq.pop();

            for(int i = 0; i < 4; i++){
                int newX = x + dir[i];
                int newY = y + dir[i+1];

                if(newX < 0 || newY < 0 || newX >= n || newY >= m){
                    continue;
                }

                int curHeight = max(h, grid[newX][newY]);

                if(dist[newX][newY] > curHeight) {
                    dist[newX][newY] = curHeight;
                    pq.push({dist[newX][newY], newX, newY});
                }
            }
        }

        return dist[n-1][m-1];
    }
};