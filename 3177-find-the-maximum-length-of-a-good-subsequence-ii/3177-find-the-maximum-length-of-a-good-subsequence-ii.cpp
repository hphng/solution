class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        // dp[val][j] = max length ending with val using j mismatches
        unordered_map<int, vector<int>> dp;
        
        // For each j, track top 2: {value, length}
        vector<pair<int,int>> best1(k+1, {-1, 0});  // global best
        vector<pair<int,int>> best2(k+1, {-1, 0});  // second best

        int ans = 0;

        for(int index = 0; index < n; index++){
            int val = nums[index];
            if(!dp.count(val)) dp[val].resize(k+1, 0);

            for(int j = 0; j <= k; j++){
                // best from different value = top 1 if top1 isn't val, else top 2
                int bestOther = 0;
                if(j > 0){
                    if(best1[j-1].first != val)
                        bestOther = best1[j-1].second;
                    else
                        bestOther = best2[j-1].second;
                }

                dp[val][j] = max(dp[val][j], bestOther) + 1;
                ans = max(ans, dp[val][j]);

                // update top 2 for j
                if(best1[j].first == val){
                    best1[j].second = dp[val][j];
                } else if(dp[val][j] >= best1[j].second){
                    best2[j] = best1[j];
                    best1[j] = {val, dp[val][j]};
                } else if(best2[j].first == val || dp[val][j] > best2[j].second){
                    best2[j] = {val, dp[val][j]};
                }
            }
        }

        return ans;
    }
};