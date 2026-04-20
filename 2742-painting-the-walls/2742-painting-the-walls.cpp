class Solution {
public:
    //basecase: index = n, remain = 0
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9)); //index, remain

        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int index = n-1; index >= 0; index--){
            for(int remain = 1; remain <= n; remain++){
                //hire
                int hire = cost[index] + dp[index+1][max(0, remain - 1 - time[index])];
                int notHire = dp[index+1][remain];

                dp[index][remain] = min(hire, notHire);
            }
        }

        return dp[0][n];
    }
};