class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for(int i = 0; i < s.length(); i++){
            int c = s[i] - 'a';
            if(first[c] == -1){
                first[c] = i;
            }
            last[c] = i;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(first[i] == -1 || first[i] == last[i]){
                continue;
            }

            vector<bool> seen(26, false);
            int left = first[i];
            int right = last[i];
            for(int j = left + 1; j < right; j++){
                int mid = s[j] - 'a';
                if(!seen[mid]){
                    ans++;
                }
                seen[mid] = true;
            }
        }
        return ans;
    }
};