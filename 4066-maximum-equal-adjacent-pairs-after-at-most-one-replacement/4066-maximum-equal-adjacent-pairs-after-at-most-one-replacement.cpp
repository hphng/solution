class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        unordered_map<string, int> mp;
        int base = 0;
        int ans = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] == nums[i]) {
                base++;
                continue;
            }

            int a = min(nums[i-1], nums[i]);
            int b = max(nums[i-1], nums[i]);
            string cur = to_string(a) + " " + to_string(b);
            mp[cur]++;

            ans = max(ans, mp[cur]);
        }
        return ans + base;
    }
};