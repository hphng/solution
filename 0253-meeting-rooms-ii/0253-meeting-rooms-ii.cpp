class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        /*
        int res = 0;
        for(int i = 0; i < round(1e6); i++){
            int cur = 0;
            for(auto interval : intervals){
                if(interval[0] <= i && i <= interval[1] ){
                    cur++;
                }
            }
            res = max(res, cur);
        }
        return res;
        */
        sort(intervals.begin(), intervals.end(), [](const vector<int> p,
        const vector<int> q){
            return p[0] < q[0];
        });
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto interval: intervals){
            if(pq.empty()){
                pq.push(interval[1]);
                continue;
            }
            int top = pq.top();
            cout << top << " "  << interval[1] << endl; 
            if(top <= interval[0]){
                pq.pop();
            }
            pq.push(interval[1]);
        }
        return pq.size();
    }
};