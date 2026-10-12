class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size();
        int m = nums2.size();

        int left = 0, right = n;

        while(left <= right) {
            //nums of element on the left side of nums1
            int partrition1 = (left + right)/2;
            //nums of element on the left side of nums2
            int partrition2 = (n + m + 1)/2 - partrition1;

            int maxLeft1 = partrition1 == 0? INT_MIN: nums1[partrition1-1];
            int minRight1 = partrition1 == n ? INT_MAX: nums1[partrition1];
            int maxLeft2 = partrition2 == 0? INT_MIN : nums2[partrition2-1];
            int minRight2 = partrition2 == m ? INT_MAX : nums2[partrition2];

            //check if the current patrition is in the right order
            //it is obvious that maxLeft1 <= maxRight1 and maxLeft2 <= maxRight2 because the arrays is sorted
            if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                //if sastify -> we choose the middle
                if((m + n) % 2 == 0){
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2))/2.0;
                } else {
                    return max(maxLeft1, maxLeft2) * 1.0;
                }
            }

            if(maxLeft1 > minRight2) {
                right = partrition1 - 1;
            } else {
                left = partrition1 + 1;
            }
        }

        return -1.0;
    }
};