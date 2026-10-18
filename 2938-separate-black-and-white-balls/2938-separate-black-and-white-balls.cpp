class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;

        int left = 0, right = s.length() - 1;
        while(left < right) {
            while(left < right && s[left] == '0') {
                left ++;
            }

            while(left < right && s[right] == '1') {
                right--;
            }

            // if(left >= right) {
            //     break;
            // }

            ans += (1LL * right - left );
            left++;
            right--;
        }
        return ans;
    }
};