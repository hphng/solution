class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }

        int n = nums.size();
        int maxValue = *max_element(nums.begin(), nums.end());
        int minValue = *min_element(nums.begin(), nums.end());

        if(maxValue == minValue) return 0;

        double bucketGap = (maxValue - minValue)/ (double) (n-1);
        int bucketSize = n;
        vector<int> bucketMax(bucketSize, INT_MIN);
        vector<int> bucketMin(bucketSize, INT_MAX);
        vector<bool> isEmpty(bucketSize, true);
        for(int i = 0; i < n; i++){
            int idx = (int) ((nums[i] - minValue) / bucketGap);
            if (idx >= bucketSize) idx = bucketSize - 1;
            bucketMax[idx] = max(bucketMax[idx], nums[i]);
            bucketMin[idx] = min(bucketMin[idx], nums[i]);
            isEmpty[idx] = false;
        }

        int prevMax = minValue;
        int maxGap = 0;
        for(int i = 0; i < bucketSize; i++){
            if(isEmpty[i])
                continue;
            maxGap = max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }
        return maxGap;
    }
};