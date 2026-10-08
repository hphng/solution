class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        long long ans = 0;

        for(int t = 0; t < 2; t++) {
            vector<vector<int>> arr;
            for(const auto& coin: coins) {
                if(t == 0) {
                    arr.push_back(coin);
                } else {
                    arr.push_back({-coin[1], -coin[0], coin[2]});
                }
            }

            sort(arr.begin(), arr.end(), [](const auto& p, const auto& q) {
                return p[0] < q[0];
            });

            int nextIndex = 0;
            long long sum = 0;

            for(int i = 0; i < arr.size(); i++) {
                int windowStart = arr[i][0];
                int windowEnd = windowStart + k - 1;

                while(nextIndex < arr.size() && arr[nextIndex][1] <= windowEnd) {
                    sum = sum + 1ll * (arr[nextIndex][1] - arr[nextIndex][0] + 1) * arr[nextIndex][2];
                    nextIndex++;
                }

                long long part = 0;
                if(nextIndex < arr.size() && arr[nextIndex][0] <= windowEnd) {
                    part = 1ll* (windowEnd - arr[nextIndex][0] + 1) * arr[nextIndex][2];
                }

                ans = max(ans, sum + part);
                //when nextIndex is inside one interval[ ] -> we need it to go to the next interval
                if(nextIndex > i) {
                    sum = sum - 1ll * (arr[i][1] - arr[i][0] + 1) * arr[i][2];
                } else {
                    nextIndex++;
                }
            }
        }

        return ans;
    }
};