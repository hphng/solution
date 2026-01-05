class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.size();

        long long ans = 0;
        int mini = INT_MAX;
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] < 0){
                    count++;
                }
                mini = min(mini, abs(matrix[i][j]));
                ans = ans + abs(matrix[i][j]);
            }
        }
        
        if(count % 2 != 0){
            ans = ans - mini *2;
        }
        return ans;
    }
};