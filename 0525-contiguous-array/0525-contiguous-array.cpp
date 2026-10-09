class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> prefix(nums.size() + 1);
        prefix[0] = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                prefix[i+1] = prefix[i] - 1;
            else {
                prefix[i+1] = prefix[i] + 1;
            }
        }
        unordered_map<int, int> firstSeen; //nun, index
        int len = 0;
        for(int i = 0; i < prefix.size();i++) {
            int cur = prefix[i];
            if(firstSeen.find(cur) != firstSeen.end()) {
                len = max(len, i - firstSeen[cur]);
            } else {
                firstSeen[cur] = i;
            }
        }

        return len;
    }
};