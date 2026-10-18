class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 0;
        for(int left = 0; left < nums.size(); left++) {
            unordered_set<int> remainder;
            int curSum = 0;

            for(int right = left; right < nums.size(); right++) {
                int value = ((nums[right] % k) + k) % k; 
                curSum = (curSum + value) % k;
                remainder.insert((2* value % k + k) %k);

                int needed = (k - value) % k;
                if(curSum == 0 || remainder.count(curSum)) {
                    ans = max(ans, right - left + 1);
                }
            }
        }
        return ans;
    }
};