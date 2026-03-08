class Solution {
public:
    void backtrack(vector<string>& ans, string& path, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(path);
            return;
        }

        if(open > 0){
            path += "(";
            backtrack(ans, path, open-1, close);
            path.pop_back();
        }

        if(close > open) {
            path += ")";
            backtrack(ans, path, open, close-1);
            path.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string path = "";
        vector<string> ans;
        backtrack(ans, path, n, n);
        return ans;
    }
};