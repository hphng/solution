class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n); //from, {to, cost}

        for(auto flight: flights){
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];

            adj[from].push_back({to, cost});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        //no. stop, current, cost
        queue<tuple<int, int, int>> q;
        q.push({0, src, 0});

        while(!q.empty()){
            auto [stops, current, cost] = q.front();
            q.pop();
                
            if(stops > k) {
                continue;
            }

            for(auto [next, price]: adj[current]){
                if(cost + price < dist[next]) {
                    dist[next] = cost + price;
                    q.push({stops + 1, next, dist[next]});
                }
            }
        }

        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};