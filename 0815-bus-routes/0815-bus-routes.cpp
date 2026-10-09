class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> adj;
        for(int routeIndex = 0; routeIndex < routes.size(); routeIndex++) {
            for(auto stop: routes[routeIndex]) {
                adj[stop].push_back(routeIndex);
            }
        }

        unordered_map<int, int> dist;
        vector<bool> routeUsed(routes.size(), false);
        dist[source] = 0;
        //source, prev
        queue<int> q;
        q.push(source);

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();

            for(int routeIndex: adj[cur]) {
                if(routeUsed[routeIndex]) {
                    continue;
                }

                routeUsed[routeIndex] = true;

                for(int next: routes[routeIndex]) {
                    if(dist.find(next) != dist.end()) {
                        continue;
                    }

                    dist[next] = dist[cur] + 1;
                    q.push(next);
                }
            }
        }

        if(dist.find(target) != dist.end()) {
            return dist[target];
        }

        return -1;
    }
};