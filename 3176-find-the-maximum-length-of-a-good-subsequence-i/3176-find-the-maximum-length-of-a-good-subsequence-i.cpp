class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[value][j] = max length subsequence ending with `value` using j mismatches
        unordered_map<int, vector<int>> dp;
        int ans = 0;

        for(int index = 0; index < nums.size(); index++){
            int val = nums[index];
            if(dp.find(val) == dp.end()){
                dp[val].resize(k+1, 0);
            }

            for(int j = 0; j <= k; j++){
                // extend with same value - free
                dp[val][j] = dp[val][j] + 1;

                // extend from any different value - costs 1 mismatch
                if(j > 0){
                    for(auto& [otherVal, vec] : dp){
                        if(otherVal != val){
                            dp[val][j] = max(dp[val][j], vec[j-1] + 1);
                        }
                    }
                }

                ans = max(ans, dp[val][j]);
            }
        }

        return ans;
    }
};