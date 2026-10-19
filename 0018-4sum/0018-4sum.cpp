class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        if(nums.size() < 4) return {};

        for (int a = 0; a < nums.size() - 3; a++) {
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }

            for (int b = a + 1; b < nums.size() - 2; b++) {
                if (b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }

                int c = b + 1;
                int d = nums.size() - 1;
                long long curTarget = 1LL * target - nums[a] - nums[b];
                while (c < d) {
                    long long sum = 1LL * nums[c] + nums[d];
                    if (sum < curTarget) {
                        c++;
                    } else if (sum > curTarget) {
                        d--;
                    } else {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                        while (c != 0 && c < d && nums[c] == nums[c - 1]) {
                            c++;
                        }

                        while (d != nums.size() - 1 && c < d &&
                               nums[d] == nums[d + 1]) {
                            d--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};