class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        vector<int> prefix(n+1, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] = nums[i-1] + prefix[i-1];
        }

        int sum = prefix[n];
        int target = sum -x;

        if(target < 0) return -1;
        int left = 0, right = 0;
        int curSum = 0;
        int ans = -1;
        while(right <= n) {
            while(prefix[right] - prefix[left] > target) {
                left++;
            }

            if(prefix[right] - prefix[left] == target){
                ans = max(ans, right - left);
            }
            right++;
        }

        return ans == -1 ? -1 : n - ans;
        
    }
};