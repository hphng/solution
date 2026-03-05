class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n < m) return "";

        unordered_map<char, int> mp;
        for(auto c: t){
            mp[c]++;
        }

        unordered_map<char, int> cur;
        int j = 0;
        string ans = "";
        for(int i = 0; i < n; i++){
            cur[s[i]]++;
            
            bool isIncluded = true;
            for(auto [c, freq]: mp){
                if(cur[c] < freq){
                    isIncluded = false;
                    break;
                }
            }

            if(!isIncluded){
                continue;
            }

            //when substring of s[j, i] contains t
            while(j <= i) {
                if(cur[s[j]] - 1 < mp[s[j]]){
                    break;
                }
                cur[s[j]]--;
                j++;
            }

            if(ans == "" || ans.length() > (i-j+1)){
                ans = s.substr(j, i - j + 1);
            }
        }
        // cout << ans << endl;
        return ans;
    }
};