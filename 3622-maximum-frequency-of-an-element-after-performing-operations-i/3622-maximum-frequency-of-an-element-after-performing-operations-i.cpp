class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> mp;
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<int> count(maxValue+1, 0);
        for(auto x : nums){
            mp[x]++;
            count[x]++;
        }

        for(int i = 1; i <= maxValue; i++){
            count[i] += count[i-1];
        }

        int maxi = 0;

        for(int num = minValue; num <= maxValue; num++){
            int left = max(minValue, num - k);
            int right = min(maxValue, num + k);
            int total = count[right] - (left? count[left-1] : 0);
            int freq = count[num] - (num? count[num-1]: 0);
            maxi = max(maxi, freq+ min(numOperations, total- freq));
        }
        return maxi;
    }
};