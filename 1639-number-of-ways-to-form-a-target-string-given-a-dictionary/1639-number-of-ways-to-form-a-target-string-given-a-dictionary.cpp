class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> memo;
    vector<vector<int>> freq;
    long long backtrack(vector<string>& words, string& target, int col, int targetIndex){
        if(targetIndex == target.length()){
            return 1;
        }
        int n = words[0].length();
        if(col == n){
            return 0;
        }

        if(memo[col][targetIndex] != -1){
            return memo[col][targetIndex];
        }
        long long ways = 0;
        //skip this col
        ways = (ways + backtrack(words, target, col+1, targetIndex))% MOD;

        //take this col
        int count = freq[col][target[targetIndex] -'a'];
        ways = (ways + count*backtrack(words, target, col+1, targetIndex+1)) % MOD;

        memo[col][targetIndex] = ways;
        return ways;
    }
    int numWays(vector<string>& words, string target) {
        int n = words[0].length();
        int m = target.length();
        memo.resize(n, vector<long long>(m, -1));

        freq.resize(n, vector<int>(26, 0));
        
        for(int i = 0; i < n; i++){
            for(auto& word: words){
                freq[i][word[i] -'a']++;
            }
        }

        int ans = backtrack(words, target, 0, 0);
        return ans;
    }
};