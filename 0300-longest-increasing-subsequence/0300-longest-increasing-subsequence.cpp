class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < dp.size(); i++){
            for(int j = i+1; j < dp.size(); j++){
                if(nums[i] < nums[j]){
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < dp.size(); i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};