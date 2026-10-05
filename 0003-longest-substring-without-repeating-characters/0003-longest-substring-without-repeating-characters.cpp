class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxi = 0;

        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++) {
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= left) {
                // cout << s[i] << " " << i << " " << left << endl;
                maxi = max(maxi, i - left);
                left = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
        }
        maxi = max(maxi, (int)s.length() - left);

        return maxi;
    }
};