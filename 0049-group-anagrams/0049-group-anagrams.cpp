class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(const string word: strs) {
            string cur = word;
            sort(cur.begin(), cur.end());
            mp[cur].push_back(word);
        }

        for(auto [_, v]: mp){
            ans.push_back(v);
        }

        return ans;
    }
};