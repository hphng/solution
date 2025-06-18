class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = 0;
        int zero2 = 0;
        long long  total1 = 0;
        long long  total2 = 0;
        for(auto x : nums1){
            if(x == 0){
                zero1++;
            }
            total1 += x;
        }

        for(auto x : nums2){
            if(x == 0){
                zero2++;
            }
            total2 += x;
        }

        long long res1 = total1 + zero1;
        long long res2 = total2 + zero2;
        if(zero1 == 0 && res2 > total1){
            return -1;
        }
        if(zero2 == 0 && res1 > total2){
            return -1;
        }
        return max(res1, res2);
    }
};