class Solution {
public:
    long long dfs(vector<vector<int>>& adj, vector<int>& values, vector<bool>& visited, int k, int& ans, int cur){
        // if(sum % k == 0){
        //     sum = 0;
        //     ans += 1;
        // }
        long long sum = values[cur];
        visited[cur] = true;
        for(auto next: adj[cur]){
            if(!visited[next]){
                sum += dfs(adj, values, visited, k, ans, next);
            }
        }
        if(sum % k == 0){
            ans += 1;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto pair: edges){
            int x = pair[0];
            int y = pair[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool> visited(n, false);
        int sum = 0, ans = 0;
        dfs(adj, values, visited, k, ans, 0);
        return ans;
    }
};