class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int lower = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int upper = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();

        int neg = lower;
        int pos = nums.size() - upper;
        return max(pos, neg);
    }
};