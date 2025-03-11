class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp {{'a', 0}, {'b', 0}, {'c', 0}};
        int ans = 0;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            mp[s[right]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                ans = ans + s.length() - right;
                mp[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};