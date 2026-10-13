class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());


        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        vector<int> findNextIndex(n);
        for(int i = 0; i < n; i++) {
            int nextIndex = lower_bound(meetings.begin(), meetings.end(), vector<int> {meetings[i][1]}) - meetings.begin();
            findNextIndex[i] = nextIndex;
        }
        for(int index = n-1; index >= 0; index--) {
            for(int started = 0; started < 2; started++) {
                int gain = meetings[index][2];
                if(started == 1) {
                    gain += meetings[index][0];
                }

                //choose
                long long last = gain;

                int nextIndex = findNextIndex[index];
                long long notLast = gain - meetings[index][1] + dp[nextIndex][1];

                //not choose
                long long notChoose = dp[index+1][started];

                dp[index][started] = max({last, notLast, notChoose});
            }
        }
        return dp[0][0];
    }
};