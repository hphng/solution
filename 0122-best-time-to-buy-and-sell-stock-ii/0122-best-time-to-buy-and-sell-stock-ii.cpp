class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0, end = 0;
        int n = prices.size();
        int ans = 0;
        while(start < n) {
            //increase the window
            int end = start;
            while(end < n-1 && prices[end] <= prices[end+1]) {
                end++;
            }
            ans += prices[end] - prices[start];
            start = end + 1;
        }

        return ans;
    }
};