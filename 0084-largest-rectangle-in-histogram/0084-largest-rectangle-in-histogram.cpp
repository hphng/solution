class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int maxi = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(st.size() == 1) {
                st.push(i);
            }

            while(st.size() > 1 && heights[st.top()] > heights[i]) {
                int curIndex = st.top();
                st.pop();

                int curArea = heights[curIndex] * (i - st.top() - 1);
                maxi = max(maxi, curArea);
            }

            st.push(i);
        }

        while(st.top() != -1 ) {
            int curIndex = st.top();
            st.pop();

            int curArea = heights[curIndex] * (heights.size() - st.top() - 1);
            maxi = max(maxi, curArea);
        }

        return maxi;
    }
};