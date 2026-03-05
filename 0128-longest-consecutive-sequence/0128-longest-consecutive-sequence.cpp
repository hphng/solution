class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto num: s){
            if(s.contains(num-1)){
                continue;
            }

            int current = 0;
            while(s.contains(num + current)){
                current++;
            }
            longest = max(longest, current);
        }
        return longest;
    }
};