class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        vector<int> heights (n, 0);

        for(int i = 0; i < m; i++) {
            //process each row
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            //after each row, monotonic stack
            stack<int> s;
            s.push(-1);

            for(int index = 0; index < heights.size(); index++){
                if(s.top() == -1 || heights[s.top()] < heights[index]){
                    s.push(index);
                    continue;
                }

                //pop out everything bigger than current height
                while(s.top() != -1 && heights[s.top()] >= heights[index]){
                    int curIndex = s.top();
                    s.pop();

                    int h = heights[curIndex];
                    // (a, b) - exclusive
                    int w = index - s.top() - 1;
                    maxArea = max(maxArea, h*w);
                }
                //everything in the stack smaller than current height
                s.push(index);
            }

            //process the remaining of the stack
            while(s.top() != -1){
                int curIndex = s.top();
                s.pop();

                int h = heights[curIndex];
                // (a, b)
                int w = n - s.top() - 1;
                maxArea = max(maxArea, h*w);
            }
        }
        return maxArea;
    }
};