class Solution {
public:
    bool canGoOver(int row, int col, int day, vector<vector<int>>& cells){
        vector<vector<int>> grid(row, vector<int>(col, 0));
        for(int i = 0; i <= day; i++){
            int x = cells[i][0]-1;
            int y = cells[i][1]-1;
            grid[x][y] = 1;
        }

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        for(int j = 0; j < col; j++){
            if(grid[0][j] == 1){
                continue;
            }
            visited[0][j] = true;
            q.push({0, j});
        } 
        vector<int> direction = {1, 0, -1, 0, 1};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(x == row-1){
                return true;
            }

            for(int d = 0; d < 4; d++){
                int newX = x + direction[d];
                int newY = y + direction[d+1];

                if(newX < 0 || newX >= row || newY < 0 || newY >= col || visited[newX][newY] || grid[newX][newY] == 1){
                    continue;
                }
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left = 0;
        int right = cells.size();
        // int mid = 0;
        while(left <= right){
            int mid = (left + right)/2;
            if(canGoOver(row, col, mid, cells)){
                left = mid + 1;
            }else {
                right = mid -1;
            }
        }      
        return left;
    }
};