class Solution {
public:
    unordered_map<char, string> mp ={
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    void backtrack(vector<string>& ans, string& cur, string& digits, int index) {
        if(digits.length() == index) {
            ans.push_back(cur);
        }

        for(char c: mp[digits[index]]) {
            cur += c;
            backtrack(ans, cur, digits, index+1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur;

        backtrack(ans, cur, digits, 0);
        return ans;
    }
};