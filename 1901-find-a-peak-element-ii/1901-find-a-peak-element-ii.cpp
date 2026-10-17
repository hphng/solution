class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();


        int leftCol = 0, rightCol = n;

        while(leftCol < rightCol) {
            int midCol = (leftCol + rightCol)/2;

            //find the larges element in one row
            int maxRow = 0;
            for(int row = 0; row < m; row++) {
                if(mat[row][midCol] > mat[maxRow][midCol]) {
                    maxRow = row;
                }
            }

            //since its already biggest with up/down -> comaoare to find with left and right
            bool biggerLeft = midCol > 0 && mat[maxRow][midCol] < mat[maxRow][midCol-1];
            bool biggerRight = midCol < n-1 && mat[maxRow][midCol] < mat[maxRow][midCol + 1];
            if(!biggerLeft && !biggerRight) {
                return {maxRow, midCol};
            }
            if(biggerLeft) {
                //left is bigger -> answer might be in left
                rightCol = midCol;
            } else {
                leftCol = midCol + 1;
            }

        }
        return {-1, -1};
    }
};