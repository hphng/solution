class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int i = 0;
        int n = prices.size();
        long long ans = 0;
        while(i < n){
            int j = i;
            while(j < n-1 && prices[j+1] == prices[j]-1){
                j++;
            }
            long long total = j - i + 1;
            ans = (total * (total + 1))/2 + ans;
            i = j + 1;
        }
        return ans;
    }
};