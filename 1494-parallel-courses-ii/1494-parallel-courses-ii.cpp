class Solution {
public:
    vector<vector<int>> adj;
    vector<int> pre, memo;
    // unordered_map<int, int> memo;
    int n, k;

    int backtrack(int bitmask){
        if(bitmask == (1 << n) - 1){
            return 0;
        }

        if(memo[bitmask] != -1){
            return memo[bitmask];
        }

        int next_mask = 0;
        for(int i = 0; i < n; i++){
            if(!(bitmask & (1 << i)) && (bitmask & pre[i]) == pre[i]){
                next_mask |= (1 << i);
            } 
        }
        int ans = n+1;
        int num =__builtin_popcount(next_mask);
        if(num > k){
            //combination
            int sub = next_mask;
            while(sub){
                if(__builtin_popcount(sub) == k){
                    ans = min(ans, 1 + backtrack(sub | bitmask));
                }
                sub = (sub-1) & next_mask;
            }
        } else {
            ans = min(ans, 1 + backtrack(next_mask | bitmask));
        }

        memo[bitmask] = ans;
        return ans;
    }
    int minNumberOfSemesters(int N, vector<vector<int>>& relations, int K) {
        n = N;
        k = K;
        adj.resize(n);
        pre.resize(n, 0);
        memo.resize(1 << n, -1);

        for(const auto& relation: relations){
            int prev = relation[0]-1;
            int next = relation[1]-1;

            adj[prev].push_back(next);
            pre[next] |= (1 << prev);
        }

        int ans = backtrack(0);
        return ans;
    }
};