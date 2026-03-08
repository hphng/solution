class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& path, int target, int start) {
        if(target == 0){
            ans.push_back(path);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if(candidates[i] <= target) {
                path.push_back(candidates[i]);
                backtrack(candidates, ans, path, target - candidates[i], i);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        backtrack(candidates, ans, path, target, 0);
        return ans;
    }
};