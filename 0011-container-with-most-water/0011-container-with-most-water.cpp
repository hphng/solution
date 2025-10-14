class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxi = min(height[left], height[right]) * (right - left);
        while( left < right){
            if(height[left] < height[right]){
                left++;
            } else {
                right --;
            }
            int curArea = min(height[left], height[right]) * (right - left);
            maxi = max(curArea, maxi);
        }
        return maxi;
    }
};