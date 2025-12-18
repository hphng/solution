class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long profit = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++){
            profit = profit + (long long) prices[i] * strategy[i];
        }
        int left = 0, right = k-1;
        int mid = (left+right)/2;
        long long cur = profit;
        //first action
        for(int i = 0; i <= mid; i++){
            cur = cur - (long long) prices[i] * strategy[i] + 0;
        }

        for(int i = mid+1; i <= right; i++){
            cur = cur - (long long) prices[i] * strategy[i] + 1 * prices[i];
        }

        profit = max(profit, cur);

        while(right < n-1){
            //original left
            cur = cur + (long long) prices[left] * strategy[left] - 0;
            //next mid should be hold
            cur = cur - prices[mid+1] * 1 +0;
            //next right should be sell
            cur = cur - prices[right+1] * strategy[right+1] + prices[right+1] * 1;
            profit = max(profit, cur);

            left++;
            mid++;
            right++;
        }
        return profit;
    }
};