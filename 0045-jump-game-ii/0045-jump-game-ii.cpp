class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j <= nums[i]; j++){
                if(i + j >= nums.size()){
                    break;
                }
                dp[i+j] = min(dp[i+j], dp[i]+ 1);
            }
        }
        // cout << endl;
        // for(auto i : dp){
        //     cout << i << " ";
        // }
        return dp[nums.size()-1];
    }
};