class Solution {
private:
    vector<vector<optional<bool>>> memo;
public:
    bool backtrack(vector<int>& nums, int index, int target) {
        if(target == 0){
            return true;
        }

        if(index >= nums.size() || target < 0) {
            return false;
        }

        if(memo[index][target] != nullopt){
            return (memo[index][target] == true);
        }

        bool result = backtrack(nums, index+1, target - nums[index]) ||
                        backtrack(nums, index+1, target);
        memo[index][target] = result;
        return result;

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums){
            sum += num;
        }
        int n = nums.size();
        if(sum % 2 != 0){
            return false;
        }
        sum /= 2;
        memo.resize(n+1, vector<optional<bool>> (sum+1, nullopt));
        return backtrack(nums, 0, sum);
    }
};