class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int first = 0;
        int count = 1;
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                count++;
            } else {
                first = count;
                count = 1;
            }

            ans = max(ans, min(count, first));
            ans = max(ans, count/2);
        }
        return ans;
    }
};