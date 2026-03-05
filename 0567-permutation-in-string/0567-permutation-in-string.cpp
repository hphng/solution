class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m){
            return false;
        }

        unordered_map<char, int> mp;
        for (auto c : s1) {
            mp[c]++;
        }
        unordered_map<char, int> check;
        for (int i = 0; i < n; i++) {
            check[s2[i]]++;
        }
        bool same = true;
        for (auto [c, _] : mp) {
            if (check[c] != mp[c]) {
                same = false;
                break;
            }
        }

        if (same)
            return true;
        for (int i = n; i < m; i++) {
            check[s2[i]]++;
            check[s2[i - n]]--;

            bool a = true;
            for (auto [c, _] : mp) {
                if (check[c] != mp[c]) {
                    a = false;
                    break;
                }
            }

            if (a)
                return true;
        }
        return false;
    }
};