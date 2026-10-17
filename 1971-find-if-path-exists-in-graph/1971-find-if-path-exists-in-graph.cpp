class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(const auto& edge: edges) {
            int from = edge[0];
            int to = edge[1];

            adj[from].push_back(to);
            adj[to].push_back(from);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);

        while(!q.empty()) {
            auto top = q.front();
            q.pop();

            if(top == destination) {
                return true;
            }

            for(auto next: adj[top]) {
                if(!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        return false;
    }
};