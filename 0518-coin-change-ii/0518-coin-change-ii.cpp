class Solution {
public:
    vector<vector<int>> memo;

    int backtrack(vector<int>& coins, int target, int index) {
        if(target == 0){
            return 1;
        }

        if(target < 0 || index >= coins.size()){
            return 0;
        }

        if(memo[target][index] != -1){
            return memo[target][index];
        }

        int take = backtrack(coins, target - coins[index], index);
        int skip = backtrack(coins, target, index+1);
        memo[target][index] = take + skip;

        return memo[target][index];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memo.resize(amount+1, vector<int>(n, -1));
        int ans = backtrack(coins, amount, 0);
        return ans;
    }
};