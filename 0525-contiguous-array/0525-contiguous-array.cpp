class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                prefix[i+1] = prefix[i] - 1;
            } else {
                //nums[i] == 1
                prefix[i+1] = prefix[i] + 1;
            }
        }

        unordered_map<int, int> mp;
        int res = 0;
        for(int i = 1; i < prefix.size(); i++){
            if(prefix[i] == 0){
                res = max(res, i);
                continue;
            }

            if(mp.find(prefix[i]) != mp.end()){
                int j = mp[prefix[i]];
                res = max(res, i - j);
            } else {
                mp[prefix[i]] = i;
            }
        }
        return res;
    }
};