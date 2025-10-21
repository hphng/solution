class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int maxi = 0;
        for(auto x: numSet){;
            //no x -1 -> start of array
            if(numSet.find(x-1) == numSet.end()){
                int cur = 1;
                while(numSet.find(x+cur) != numSet.end()){
                    cur++;
                }
                maxi = max(cur, maxi);
            }
        }
        return maxi;
    }
};