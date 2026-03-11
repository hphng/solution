class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int cur = 1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                maxi = max(maxi, 0);
                cur = 1;
                continue;
            }
            cur*=nums[i];
            // cout << cur << endl;
            maxi = max(maxi, cur);
        }
        cur = 1;
        for(int i = nums.size()- 1; i >= 0; i--){
            if(nums[i] == 0){
                cur = 1;
                continue;
            }
            cur*= nums[i];
            maxi = max(maxi, cur);
        }
        return maxi;
    }
};