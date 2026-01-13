class Solution {
public:
    double const epsilon = 1e-5;

    double calculateDiffrentiate(double line, vector<vector<int>>& squares){
        double totalAbove = 0;
        double totalBelow = 0;
        
        for(auto& square: squares){
            double x = static_cast<double> (square[0]);
            double y = static_cast<double> (square[1]);
            double l = static_cast<double> (square[2]);
            //line > y + l
            double curArea = l * l;
            if(line >= y + l) {
                totalBelow += curArea;
            //line < y 
            } else if(line <= y ){
                totalAbove += curArea;
            } else {
                double aboveHeight = (y+l) - line;
                double belowHeight =  line - y;

                totalAbove += l * aboveHeight;
                totalBelow += l * belowHeight;
            }
        }
        return totalAbove - totalBelow;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = 0;
        double high = 2*1e9;

        while(high - low > epsilon) {
            double mid = (low + high)/2.0;
            double diff = calculateDiffrentiate(mid, squares);

            if(diff > epsilon){
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};