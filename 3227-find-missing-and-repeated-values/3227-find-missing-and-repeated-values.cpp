class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int diff = 0;
        int squareDiff = 0;
        int n = grid.size();
        int k = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                diff = diff + grid[i][j] - k;
                squareDiff = squareDiff + grid[i][j] * grid[i][j] - k*k;
                k++;
            }
        }

        // for(int i = 1; i <= n*n; i++){
        //     originalTotal += i;
        //     originalSquareTotal += i*i;
        // }

        bool b = true;
        if(diff < 0) {
            b = false;
        }
        diff = abs(diff);
        squareDiff = abs(squareDiff);
        // cout << diff << " " << squareDiff;
        int plus = squareDiff / diff;
        int x = (plus + diff)/2;
        int y = plus - x;
        if(b){
            return {x, y};
        }
        return {y, x};
    }
};