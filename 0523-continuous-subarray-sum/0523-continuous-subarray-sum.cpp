class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        if(k == 1) return true;
        vector<int> dp(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] % k;
        }

        unordered_map<int, int> mp;
        int cur = 0;
        mp[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            cur += nums[i];
            cur = cur % k;
            if(mp.find(cur) != mp.end()){
                if(i - mp[cur] >= 2){
                    return true;
                }
            }
            else{
                mp[cur] = i;
            }
        }
        return false;
    }
};