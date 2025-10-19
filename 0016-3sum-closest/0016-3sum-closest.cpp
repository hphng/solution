class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MAX, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int twoSum = target - nums[i];
            int left = i+1, right = n-1;
            while(left < right){
                int curSum = nums[i] + nums[left] + nums[right];
                if(abs(curSum - target) < diff){
                    res = curSum;
                    diff = abs(curSum-target);
                }
                // cout << nums[i] << " " << nums[left] << " " << nums[right] << endl;
                if(curSum < target){
                    left++;
                } else if(curSum > target){
                    right--;
                } else {
                    return curSum;
                }
            }
        }
        return res;
    }
};