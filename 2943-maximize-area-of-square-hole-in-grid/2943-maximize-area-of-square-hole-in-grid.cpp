class Solution {
public:
    int longestConsecutive(vector<int>& bars){
        int ans = 1;
        int cur = 1;
        for(int i = 1; i < bars.size(); i++){
            if(bars[i] == bars[i-1] + 1){
                cur++;
            } else {
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(ans, cur);
        return ans;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int h = longestConsecutive(hBars) + 1;
        int v = longestConsecutive(vBars) + 1;

        int len = min(h, v);
        return len*len;
    }
};