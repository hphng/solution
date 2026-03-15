class Solution {
public:
    vector<vector<int>> memo;
    int backtrack(string& word1, int i, string& word2, int j) {
        int l1 = word1.length();
        int l2 = word2.length();
        if(i == l1) {
            return l2 - j;
        }
        if(j == l2){
            return l1 - i;
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        if(word1[i] == word2[j]){
            int ans = backtrack(word1, i+1, word2, j+1);
            memo[i][j] = ans;
            return ans;
        }

        int insert = 1 + backtrack(word1, i, word2, j+1);
        int del = 1 + backtrack(word1, i+1, word2, j);
        int replace = 1 + backtrack(word1, i+1, word2, j+1);

        int ans = min(insert, min(del, replace));
        memo[i][j] = ans;
        return ans;
    }
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        memo.resize(l1, vector<int>(l2, -1));
        int ans = backtrack(word1, 0, word2, 0);
        return ans;
    }
};