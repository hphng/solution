class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> mp(m+n);
        for(int col = 0; col < n; col++){
            for(int row = 0; row < m; row++){
                int sum = col + row;
                mp[sum].push_back(mat[col][row]);
            }
        }

        // for(int i = 0; i < mp.size(); i++){
        //     for(int j = 0; j < mp[i].size(); j++){
        //         cout << mp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<int> ans;
        for(int level = 0; level <mp.size(); level++){
            if(level%2 == 0){
                reverse(mp[level].begin(), mp[level].end());
            }
            ans.insert(ans.end(), mp[level].begin(), mp[level].end());
        }
        return ans;
    }
};