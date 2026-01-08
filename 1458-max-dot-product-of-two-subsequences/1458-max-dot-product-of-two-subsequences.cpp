class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int cur = nums1[i] * nums2[j];
                // dp[i][j] = product;

                if(i > 0 && j > 0){
                    cur = max(cur, cur + dp[i-1][j-1]);
                }

                if(i > 0){
                    cur = max(cur, dp[i-1][j]);
                }

                if(j > 0){
                    cur = max(cur, dp[i][j-1]);
                }
                dp[i][j] = cur;
            }
        }
        return dp[m-1][n-1];
    }
};