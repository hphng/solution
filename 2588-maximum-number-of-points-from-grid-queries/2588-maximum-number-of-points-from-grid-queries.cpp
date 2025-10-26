class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int, int>> sortedQueries;
        for(int i = 0; i < queries.size(); i++){
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end(), [](pair<int, int> p, pair<int, int>q){
            return p.first < q.first;
        });

        sort(queries.begin(), queries.end());
        vector<int> ans (queries.size(), 0);
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq; // value, i, j
        int points = 0;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        vector<int> direction = {1, 0, -1, 0, 1};
        for(auto [query, queryIndex] : sortedQueries){
            while(!pq.empty() && get<0>(pq.top()) < query){
                auto [cur, x, y] = pq.top();
                pq.pop();
                points++;
                for(int i = 0; i < 4; i++){
                    int newX = x + direction[i];
                    int newY = y + direction[i+1];
                    if(newX < 0 || newY < 0 || newX >= m || newY >= n || visited[newX][newY]){
                        continue;
                    }

                    pq.push({grid[newX][newY], newX, newY});
                    visited[newX][newY] = true;
                }
            }
            ans[queryIndex] = points;
        }
        return ans;
    }
};