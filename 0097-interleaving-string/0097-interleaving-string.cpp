class Solution {
public:
    vector<vector<optional<bool>>>  memo;
    bool backtrack(string& s1, string& s2, string& s3, int i, int j, int k) {
        if(i == s1.length()) {
            return s2.substr(j) == s3.substr(k);
        }

        if(j == s2.length()) {
            return s1.substr(i) == s3.substr(k);
        }

        if(memo[i][j].has_value()) {
            return memo[i][j].value();
        }

        bool ans = false;
        if(s1[i] == s3[k]) {
            ans |= backtrack(s1, s2, s3, i+1, j, k+1);
        }

        if(s2[j] == s3[k]) {
            ans |= backtrack(s1, s2, s3, i, j+1, k+1);
        }

        memo[i][j] = ans;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();

        if(l1 + l2 != l3) {
            return false;
        }

        vector<vector<bool>> dp(l1+1, vector<bool> (l2+1, false));
        dp[0][0] = true;

        for(int i = 1; i < l1+1; i++) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }

        for(int j = 1; j < l2+1; j++) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }

        for(int i = 1; i < l1+1; i++) {
            for(int j = 1; j < l2+1; j++) {
                dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return dp[l1][l2];
        // return backtrack(s1, s2, s3, 0, 0, 0);
    }
};