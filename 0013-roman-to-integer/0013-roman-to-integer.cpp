class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, {'V' , 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = mp[s[0]];
        for(int i = 1; i < s.length(); i++) {
            char cur = s[i];
            char prev = s[i-1];

            if(mp[prev] < mp[cur]) {
                ans = ans - 2*mp[prev] + mp[cur];
            } else {
                ans += mp[cur];
            }
        }

        return ans;
    }
};