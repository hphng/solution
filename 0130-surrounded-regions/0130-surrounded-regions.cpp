class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        //bfs
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'Z';
                q.push({i, 0});
            }

            if(board[i][n-1] == 'O'){
                board[i][n-1] = 'Z';
                q.push({i, n-1});
            }
        }

        for(int j = 1; j < n-1; j++){
            if(board[0][j] == 'O'){
                board[0][j] = 'Z';
                q.push({0, j});
            }

            if(board[m-1][j] == 'O'){
                board[m-1][j] = 'Z';
                q.push({m-1, j});
            }
        }
        vector<int> direction = {1, 0, -1, 0, 1};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int newX = x + direction[d];
                int newY = y + direction[d+1];

                if(newX < 0 || newX >= m || newY < 0 || newY >= n || board[newX][newY] != 'O'){
                    continue;
                }
                // visited[newX][newY] = true;
                board[newX][newY] = 'Z';
                q.push({newX, newY});
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }

                if(board[i][j] == 'Z'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};