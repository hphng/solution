class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();
        for(int i = n-1; i >0 ; i--){
            if(nums[i] > nums[i-1]){
                pivot = i - 1;
                break;
            }
        }

        if(pivot == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = n-1; i >= 0; i-- ){
            if(nums[pivot] < nums[i]){
                swap(nums[pivot], nums[i]);
                reverse(nums.begin() + pivot + 1, nums.end());
                break;
            }
        }

        // reverse(nums.begin() + )
    }
};