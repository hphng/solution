class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);

        for(int i = 1; i < n+1; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        //now we need to find prefix[j+1] - prefix[i] = k = sum(i, ... j)
        unordered_map<int, int> mp;
        int count = 0;
        for(int i = 0; i < n+1; i++) {
            int needed = k + prefix[i];
            if(mp.find(prefix[i]) != mp.end()) {
                count += mp[prefix[i]] ;
            }
            mp[needed]++;
        }

        return count;
    }
};