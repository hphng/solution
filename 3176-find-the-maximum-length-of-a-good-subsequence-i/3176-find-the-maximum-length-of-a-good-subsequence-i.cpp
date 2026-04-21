class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        //prevIndex, k
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        //prev
        vector<vector<int>> prev(n+1, vector<int>(k+1, 0));

        //basecase: index reach n -> 0, for2d array, its basically the whole array?
        for(int prevIndex = 0; prevIndex <= n; prevIndex++){
            for(int K = 0; K <= k; K++){
                dp[prevIndex][K] = 0;
            }
        }

        for(int index = n-1; index >= 0; index--){
            for(int prevIndex = 0; prevIndex <= n; prevIndex++){
                if(prevIndex < n && prevIndex > index){
                    continue;
                }

                for(int K = 0; K <= k; K++){
                    int choose = 0;
                    if(prevIndex == n || nums[prevIndex] == nums[index]){
                        choose = 1 + prev[index][K];
                    } else if(nums[prevIndex] != nums[index] && K > 0){
                        choose = 1 + prev[index][K-1];
                    }

                    int notChoose = prev[prevIndex][K];

                    dp[prevIndex][K] = max(choose, notChoose);
                }
            }

            prev = dp;
        }

        return dp[n][k];

    }
};