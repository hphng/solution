class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> mp;
        int n = x.size();
        for(int i = 0; i < n; i++){
            int curX = x[i];
            int curY = y[i];
            mp[curX] = max(mp[curX], curY);
        }

        priority_queue<int> maxQ;
        for(auto pair: mp){
            maxQ.push(pair.second);
        }

        int ans = 0;
        if(maxQ.size() <= 2){
            return -1;
        }

        for(int i = 0; i < 3; i++){
            int cur = maxQ.top();
            maxQ.pop();
            ans += cur;
        }
        return ans;
    }
};