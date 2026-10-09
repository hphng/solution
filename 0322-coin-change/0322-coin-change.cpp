class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> ans (amount + 1, INT_MAX - 1);

        for(int i = 0; i <= amount; i++) {
            for(const auto coin: coins) {
                if(i == coin) {
                    ans[i] = 1;
                    continue;
                }

                if( i - coin >= 0) {
                    ans[i] = min(ans[i], ans[i-coin]+ 1);
                }
            }
        }
        if(ans[amount] == INT_MAX -1) {
            return -1;
        }
        return ans[amount];
    }
};