class Solution {
public:
    void backtrackByLevel(string base, int i, unordered_map<string, vector<string>>& mp, unordered_set<string>& ans, string current){
        int n = base.length();
        if(i >= n){
            ans.insert(current);
            return;
        }
        string s;
        s.push_back(base[i-1]);
        s.push_back(base[i]);
        if(mp.find(s) == mp.end()){
            return;
        }
        //found upper level
        for(auto upper: mp[s]){
            // cout << upper << " " << current << endl;
            backtrackByLevel(base, i+1, mp, ans, current + upper);
        }
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<string>> mp;
        for(auto s: allowed){
            string base = s.substr(0, 2);
            string top = s.substr(2, 1);
            mp[base].push_back(top);
        }
        int n = bottom.size();
        // vector<string> prev = {bottom};
        unordered_set<string> ans = {bottom};
        for(int i = 0; i < n-1; i++){
            unordered_set<string> cur;
            for(auto s: ans){
                backtrackByLevel(s, 1, mp, cur, "");
            }
            if(cur.empty()){
                return false;
            }
            ans = cur;
        }
        return ans.size() >= 1;
    }
};