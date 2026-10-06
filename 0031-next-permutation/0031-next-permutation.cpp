class Solution {
public:
    void swap(vector<int>& nums, int i , int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void nextPermutation(vector<int>& nums) {
        int p1 = -1;

        for(int i = nums.size() - 1; i > 0; i--) {
            if(nums[i] > nums[i-1]) {
                p1 = i - 1;
                break;
            }
        }    

        if(p1 == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] > nums[p1]) {
                swap(nums, i, p1);
                break;
            }
        }

        sort(nums.begin() + p1 + 1, nums.end());
    }
};