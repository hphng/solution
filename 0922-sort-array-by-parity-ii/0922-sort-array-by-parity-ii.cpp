class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd = 1;

        int n = nums.size();
        for(int i = 0; i < n; i+=2) {
            if(nums[i] % 2 == 0) {
                continue;
            }

            while(nums[odd] % 2 != 0) {
                odd+=2;
            }

            swap(nums[odd], nums[i]);
        }
        return nums;
    }
};