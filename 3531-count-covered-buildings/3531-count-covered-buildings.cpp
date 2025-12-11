class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int, int>> xRanges; //row, (min, max)
        unordered_map<int, pair<int, int>> yRanges;  //col, (min, max)

        for(auto& b: buildings){
            int x = b[0];
            int y = b[1];

            if(xRanges.find(y) == xRanges.end()){
                xRanges[y] = {x, x};
            }
            
            int xMin = min(xRanges[y].first, x);
            int xMax = max(xRanges[y].second, x);
            xRanges[y] = {xMin, xMax};

            if(yRanges.find(x) == yRanges.end()){
                yRanges[x] = {y, y};
            }

            int yMin = min(yRanges[x].first, y);
            int yMax = max(yRanges[x].second, y);
            yRanges[x] = {yMin, yMax};
        }

        int cover = 0;
        for(auto& b: buildings){
            int x = b[0];
            int y = b[1];
            auto xx = xRanges[y];
            auto yy = yRanges[x];
            // cout << "ha" << endl;
            // cout << x << " " << y << endl;
            // cout << xx.first << " " << xx.second << endl;
            // cout << yy.first << " " << yy.second << endl; 
            if(xx.first < x && x < xx.second && yy.first < y && y < yy.second){
                cover++;
            }
        }
        return cover;
    }
};