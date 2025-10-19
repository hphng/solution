class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }

            int twoSum = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right){
                int curSum = nums[left] + nums[right];
                if(curSum < twoSum){
                    left++;
                } else if(curSum > twoSum){
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while(nums[left] == nums[left-1] && left < right){
                        left++;
                    }
                    right--;
                    while(nums[right] == nums[right+1] && left < right){
                        right--;
                    }
                }
            }
        }
        return res;
    }
};