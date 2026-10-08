class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size(), m = a[0].size();
        int i = 0, j = m - 1;
        for(int i = 0; i < n && j >= 0;)
        {
            if(a[i][j] == target)
                return true;
            else if(a[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};