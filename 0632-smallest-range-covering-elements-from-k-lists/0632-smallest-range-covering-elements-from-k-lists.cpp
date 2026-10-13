class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //current value, current array index, current element index in array
        priority_queue<
            tuple<int, int, int>, 
            vector<tuple<int, int, int>>, 
            greater<tuple<int, int, int>> 
        > pq;
        
        int curMax = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            curMax = max(curMax, nums[i][0]);
        }
        vector<int> ans = {INT_MIN/2 , INT_MAX/2};
        while(!pq.empty()) {
            auto [value, arrayIndex, elementIndex] = pq.top();
            pq.pop();

            if(curMax - value < ans[1] - ans[0]) {
                ans[0] = value;
                ans[1] = curMax;
            } else if(curMax - value == ans[1] - ans[0]){
                if(value < ans[0]) {
                    ans[0] = value;
                    ans[1] = curMax;
                }
            }

            if(elementIndex + 1 < nums[arrayIndex].size()) {
                curMax = max(curMax, nums[arrayIndex][elementIndex+1]);
                pq.push({nums[arrayIndex][elementIndex + 1], arrayIndex, elementIndex + 1});
            } else {
                break;
            }
        }

        return ans;
    }
};