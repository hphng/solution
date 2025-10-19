class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        for(auto num: nums){
            if(num == 0){
                zeros++;
            }
        }
        int i = 0, j = 0;
        while(i < nums.size()){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++; i++;
            } else{
                i++;
            }
        }

        for(int i = nums.size() - zeros; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};