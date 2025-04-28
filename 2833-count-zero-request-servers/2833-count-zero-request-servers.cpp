class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto const& p, auto const& q){
            return p[1] < q[1];
        });
        vector<pair<int, int>> q;
        vector<int> cnt(n+1, 0);
        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        int active = 0, L = 0, R = 0;
        vector<int> ans (q.size(), 0);
        for(auto pair: q){
            int idx = pair.second;
            int time = pair.first;
            while(R < logs.size() && logs[R][1] <= time){
                int server = logs[R][0];
                if(cnt[server] == 0){
                    active++;
                }
                cnt[server]++;
                R++;
            }
            while(L < logs.size() && logs[L][1] < time - x){
                int server = logs[L][0];
                cnt[server]--;
                if(cnt[server] == 0){
                    active--;
                }
                L++;
            }
            int cur = n - active;
            ans[idx] = cur;
        }
        return ans;
    }
};