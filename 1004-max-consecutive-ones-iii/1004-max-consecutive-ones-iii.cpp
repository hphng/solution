class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int count = k;
        int n = nums.size();

        int cur = 0;
        int maxi = 0;
        while(start < n && end < n) {
            if(nums[end] == 1) {
                
            } else {
                //for now nums[i] = 0 only
                if(count == 0) {
                    while(start < end && nums[start] == 1) {
                        start++;
                    }
                    //loop end when start == 0
                    start++;
                    count++;
                }

                count--;
            }
            maxi = max(maxi, end - start + 1);
            end++;
        }
        return maxi;
    }
};