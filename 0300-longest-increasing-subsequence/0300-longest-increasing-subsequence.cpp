class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left < right) {
            int mid = (left + right)/2;
            
            if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }  

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(ans.size() == 0 || ans.back() < nums[i]){
                ans.push_back(nums[i]);
            } else {
                int index = binarySearch(ans, nums[i]);
                ans[index] = nums[i];
            }
        }
        return ans.size();    
    }
};