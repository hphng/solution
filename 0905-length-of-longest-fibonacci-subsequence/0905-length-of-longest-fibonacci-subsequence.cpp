class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        //current index -> previndex
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]] = i;
        }
        int maxi = 0;
        for(int curr = 0; curr < arr.size(); curr++){
            for(int prev = 0; prev < curr; prev++){
                int x = arr[curr] - arr[prev];
                int valid = -1;
                if(mp.find(x) != mp.end()){
                    valid = mp[x];
                } else {
                    valid = -1;
                }

                if(valid < 0){
                    dp[prev][curr] = 2;
                    maxi = max(maxi, dp[prev][curr]);
                    continue;
                }

                if(x < arr[prev]){
                    dp[prev][curr] = dp[valid][prev] + 1;
                } else {
                    dp[prev][curr] = 2;
                }
                maxi = max(maxi, dp[prev][curr]);
            }
        }

        // for(int i = 0; i < dp.size(); i++){
        //     for(int j = 0; j < dp[0].size(); j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if(maxi == 2){
            return 0;
        }
        return maxi;
    }
};