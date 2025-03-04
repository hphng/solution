class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX-1);
        dp[0] = 0;
        for(int cost = 1; cost < dp.size(); cost++){
            for(auto coin: coins){
                if(cost < coin){
                    continue;
                }
                dp[cost] = min(dp[cost-coin] + 1, dp[cost]);
            }
        }
        if(dp[amount] > INT_MAX-2){
            return -1;
        }
        return dp[amount];
    }
};