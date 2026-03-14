class Solution {
public:
    vector<vector<int>> memo;

    int backtrack(vector<int>& prices, int index, bool isHolding) {
        int n = prices.size();
        if(index >= n){
            return 0;
        }

        if(memo[index][isHolding] != -1) {
            return memo[index][isHolding];
        }

        int result = 0;

        if(isHolding){
            //HOLD stock -> only sell or skip
            int sell = prices[index] + backtrack(prices, index+2, false);
            int skip = backtrack(prices, index+1, true);

            result = max(sell, skip);
        } else {
            //NOT HOLDING STOCK -> only buy or skip
            int buy = -prices[index] + backtrack(prices, index+1, true);
            int skip = backtrack(prices, index+1, false);
            result = max(buy, skip);
        }

        memo[index][isHolding] = result;
        return memo[index][isHolding];

    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memo.resize(n, vector<int>(2, -1));
        int ans = backtrack(prices, 0, false);
        return memo[0][false];
    }
};