class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int startFreq = 0;
        for(auto x : nums){
            if(x == k){
                startFreq++;
            }
        }

        int maxFreq = 0;
        for(int val = 1; val <= 50; val++){
            if(val == k){
                continue;
            }
            int maxCur = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == k){
                    maxCur--;
                }

                if(nums[i] == val){
                    maxCur++;
                }
                maxCur = max(maxCur, 0);
                maxFreq = max(maxFreq, maxCur);
            }
        }
        return maxFreq + startFreq; 
    }
};