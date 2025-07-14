class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(matrix[r][c] == 0){
                    row[r] = true;
                    col[c] = true;
                }
            }
        }

        for(int r = 0; r < m; r++){
            if(!row[r]){
                continue;
            }

            for(int c = 0; c < n; c++){
                matrix[r][c] = 0;
            }
        }

        for(int c = 0; c < n; c++){
            if(!col[c]){
                continue;
            }
            for(int r = 0; r < m; r++){
                matrix[r][c] = 0;
            }
        }
        
    }
};