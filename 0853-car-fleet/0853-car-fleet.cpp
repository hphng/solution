class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(),[] (pair<int, int> p, pair<int, int> q){
            return p.first > q.first;
        });

        stack<double> st;
        for(int i = 0; i < n; i++){
            double x = (target - cars[i].first)/(double) cars[i].second;
            if(st.empty()){
                st.push(x);
                continue;
            }
            while(!st.empty() && st.top() < x) {
                st.push(x);
            }
        }

        return st.size();
    }
};