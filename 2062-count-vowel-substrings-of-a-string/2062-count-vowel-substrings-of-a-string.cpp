class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<char, int> last;
        last['a'] = -1;
        last['o'] = -1;
        last['e'] = -1;
        last['i'] = -1;
        last['u'] = -1;

        int ans = 0, conso = -1;
        
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            if(last.find(c) == last.end()) {
                conso = i;
            } else {
                last[c] = i;
                int mini = min({last['a'], last['e'], last['i'], last['o'], last['u']});
                ans = ans + max(mini - conso, 0);
            }
        }
        return ans;
    }
};