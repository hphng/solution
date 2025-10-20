class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for(auto p: power){
            mp[p]++;
        }
        vector<int> sortPower;
        for(auto pair: mp){
            sortPower.push_back(pair.first);
        }

        sort(sortPower.begin(), sortPower.end());
        int n = power.size();

        for(auto i : sortPower){
            cout << i << " ";
        }
        vector<long long> dp(sortPower.size(), 0);
        long long best = 0;
        for(int i = 0, j = 0; i < sortPower.size(); i++){
            while(j < i && sortPower[j] < sortPower[i] - 2){
                best = max(best, dp[j]);
                j++;
            }
            dp[i] = best + mp[sortPower[i]] * (long long) sortPower[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
};