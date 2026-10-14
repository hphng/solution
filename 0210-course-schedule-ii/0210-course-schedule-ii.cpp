class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(const auto& pair: prerequisites) {
            int prev = pair[1];
            int next = pair[0];

            adj[prev].push_back(next);
            indegree[next]++;
        }

        queue<int> q;
        vector<int> order;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            order.push_back(cur);

            for(auto next: adj[cur]) {
                indegree[next]--;
                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if(order.size() != numCourses) {
            return {};
        }

        return order;
    }
};