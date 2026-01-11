class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        //monotonic stack
        stack<int> s;
        s.push(-1);
        for(int i = 0; i < heights.size(); i++){
            if(s.top() == -1) {
                s.push(i);
                continue;
            }

            if(heights[s.top()] < heights[i]){
                s.push(i);
                continue;
            }

            //have elements in the stack + current height > top of stack
            while(s.top() != -1 && heights[s.top()] >= heights[i]) {
                int curIndex = s.top();
                s.pop();

                int h = heights[curIndex];
                //take width = between index a and b (a, b) (exclusive)
                int w = i - s.top() - 1;
                maxArea = max(maxArea, h*w);
            }
            //after pop out every greater height
            s.push(i);
        }

        //process remaining index in stack
        int last = heights.size();
        while(s.top() != -1){
            int curIndex = s.top();
            s.pop();

            int h = heights[curIndex];
            int w = last - s.top() - 1;
            maxArea = max(maxArea, h*w);
        }
        return maxArea;
    }
};