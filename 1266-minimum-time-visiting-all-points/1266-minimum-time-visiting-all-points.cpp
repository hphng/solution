class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0; i < points.size() - 1; i++){
            auto x = points[i];
            auto y = points[i+1];

            int cur = max(abs(x[0] - y[0]), abs(x[1] - y[1]));
            ans += cur;
        }
        return ans;
    }
};