class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> unique;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int target = -nums[i];
            int left = i + 1, right = n - 1;
            while(left < right){
                if(nums[left] + nums[right] == target){
                    unique.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    continue;
                }
                 
                if(nums[left] + nums[right] < target){
                    left++;
                } else {
                    right--;
                }
            }
        }

        vector<vector<int>> ans(unique.begin(), unique.end());

        return ans;
    }
};