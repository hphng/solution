class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(auto x: nums){
            sum += x;
        }
        int r = sum % p;
        int n = nums.size();

        if(r == 0) return 0;

        unordered_map<int, int> mp; //remainder, closet index
        mp[0] = -1;
        int ans = INT_MAX;
        int prefix = 0;
        for(int i = 0; i < n; i++){
            prefix = (prefix + nums[i]) % p;
            int curRemainder = (prefix - r + p) % p;
            if(mp.find(curRemainder) != mp.end()){
                ans = min(ans, i - mp[curRemainder]);
            }
            mp[prefix] = i;
        }
        if(ans == INT_MAX || ans == n){
            return -1;
        }
        return ans;
    }
};