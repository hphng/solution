class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> mp;
        unordered_set<string> unique;
        for(int i = 0; i < s.length(); i++){
            int c = s[i];
            mp[c].push_back(i);
        }

        for(auto pair: mp){
            char c = pair.first;
            vector<int> cur = pair.second;
            if(cur.size() < 2){
                continue;
            }
            //> = 2 size
            int left = cur[0];
            int right = cur[cur.size()-1];
            for(int i = left+1; i < right; i++){
                string one;
                one += s[left];
                one += s[i];
                one += s[right];
                unique.insert(one);
            }
        }
        return unique.size();
    }
};