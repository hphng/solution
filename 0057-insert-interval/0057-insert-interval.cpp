class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;
        int n = intervals.size();
        int& newStart = newInterval[0];
        int& newStop = newInterval[1];
        for(auto interval : intervals){
            if(interval[1] < newInterval[0]){
                ans.push_back(interval);
            }else if(interval[0] > newInterval[1]){
                ans.push_back(newInterval);
                newInterval = interval;
            } else {
                newStart = min(newInterval[0], interval[0]);
                newStop = max(newInterval[1], interval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};