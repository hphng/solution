    class Solution {
    public:
        int maximumAND(vector<int>& nums, int k, int m) {
            int ans = 0;
            for(int b = 30; b >= 0; b--){
                int candidate = ans | (1 << b);
                vector<long long> cost;
                for(int i = 0; i < nums.size(); i++) {
                    int n = nums[i];
                    long long miss = candidate & ~n; //find all missing bit from candidate
                    if(miss == 0) {
                        cost.push_back(0);
                        continue;
                    }
                    long long j = 63 - __builtin_clzll(miss); // find the highest missing bit from candidate
                    long long above = (n >> (j+1)) << (j+1); // take all the bit above + flip the position j+1 as 1 for the bit above
                    long long x = above | 1LL << j | candidate; //take all the bit above + the current hihgest missing + all the bit from candidate  
                    cost.push_back(x - n);
                }

                sort(cost.begin(), cost.end());
                long long curSum = 0;
                for(int count = 0; count < m; count++){
                    curSum += cost[count];
                }

                if(curSum <= k) {
                    ans = candidate;
                }
            }

            return ans;
        }
    };