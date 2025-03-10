class Solution {
public:
    void dfs(vector<string>& ans, int n, int open, int close, string cur){
        if(cur.length() == 2*n && open == close){
            ans.push_back(cur);
        }

        if(open < n){
            dfs(ans, n, open + 1, close, cur + "(");
        }

        if(close < open){
            dfs(ans, n, open, close+1, cur + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, n, 0, 0, "");
        return ans;
    }
};