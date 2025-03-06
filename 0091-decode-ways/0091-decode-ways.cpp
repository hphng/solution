class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, 0);
        if(s[0] == '0'){
            return 0;
        }
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i < dp.size(); i++){
            int oneDigit = s[i-1] - '0';
            int twoDigit = stoi(s.substr(i-2, 2));
            if(1 <= oneDigit && oneDigit <= 9){
                dp[i] += dp[i-1];
            }
            if(10 <= twoDigit && twoDigit <= 26){
                dp[i] += dp[i-2];
            }

        }
        // for(auto i : dp){
        //     cout << i << " ";
        // }
        return dp[s.length()];
    }
};