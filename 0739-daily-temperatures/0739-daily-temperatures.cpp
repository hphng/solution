class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //monotonic stack
        int n = temperatures.size();
        stack<int> cooler;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            if(cooler.empty()){
                cooler.push(i);
                continue;
            }

            //not empty
            while(!cooler.empty() && temperatures[cooler.top()] < temperatures[i]){
                int top = cooler.top();
                ans[top] = i - top;
                cooler.pop();
            }
            cooler.push(i);
        }
        return ans;
    }
};