class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int area = min(height[l], height[r]) * (r- l);
        while(l < r){
            if(height[l] < height[r]){
                l++;
            } else if(height[l] > height[r]){
                r--;
            } else {
                l++;
                r--;
            }
            int cur = min(height[l], height[r]) * (r-l);
            area = max(area, cur);
        }
        return area;
    }
};