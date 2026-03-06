class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        //consider 2d array as an plain array from 0 to n*m-1 then binary search
        int left = 0, right = m * n-1;
        int mid;
        while(left <= right){
            mid = left + (right - left)/2;
            int x = mid / n;
            int y = mid % n;
            if(matrix[x][y] == target)
                return true;
            
            if(matrix[x][y] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;

    }
};