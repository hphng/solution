class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        int ans = INT_MAX;
        deque<int> dq;
        for(int i = 0; i <= n; i++) {

            while(!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefix[dq.back()] >= prefix[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        if(ans == INT_MAX) return -1;
        return ans;
    }
};