class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int ans = INT_MAX;
        int i = 0, j = 0;
        while(i <= j && j < nums.size()){
            sum += nums[j];
            cout << sum << endl;
            while(sum >= target){
                ans = min(ans, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};