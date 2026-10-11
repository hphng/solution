class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        int ans = 0;
        for(int pass = 0; pass < 2; pass++) {
            vector<vector<int>> seq;
            for(int i = 0; i < tiles.size(); i++) {
                if(pass == 0) {
                    seq.push_back({tiles[i][0], tiles[i][1]});
                } else {
                    seq.push_back({-tiles[i][1], -tiles[i][0]});
                }
            }

            sort(seq.begin(), seq.end());

            int nextIndex = 0;
            int sum = 0;
            for(int i = 0; i < seq.size(); i++) {
                int windowEnd = seq[i][0] + carpetLen - 1;

                while(nextIndex < seq.size() && windowEnd >= seq[nextIndex][1]) {
                    sum += (seq[nextIndex][1] - seq[nextIndex][0] + 1);
                    nextIndex++;
                }

                //calculate partial
                int partial = 0;
                if(nextIndex < seq.size() && seq[nextIndex][0] <= windowEnd) {
                    partial = windowEnd - seq[nextIndex][0] + 1;
                }

                ans = max(ans, sum + partial);
                if(nextIndex > i) {
                    sum -= (seq[i][1] - seq[i][0] + 1);
                } else {
                    nextIndex = i + 1;
                }
            }

        }
        return ans; 
    }
};