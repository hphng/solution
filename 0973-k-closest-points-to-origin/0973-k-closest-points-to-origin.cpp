class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < points.size(); i++) {
            auto point = points[i];
            int x = point[0];
            int y = point[1];

            int distance = x*x + y*y;
            pq.push({distance, i});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [distance, index] = pq.top();
            ans.push_back(points[index]);
            pq.pop();
        }
        return ans;
    }
};