class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = (left + right)/2;
            
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        int first = left;
        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }

        left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right + 1) /2;
            if(nums[mid] <= target) {
                left = mid;
            } else {
                right = mid -1;
            }
        }

        return {first, right};
    }
};