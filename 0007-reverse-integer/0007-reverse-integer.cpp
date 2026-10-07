class Solution {
public:
    int reverse(int x) {
        //setup
        bool plus = x > 0;
        if(plus) x = -x;

        //now x is guaranteed to be negative
        int current_power = 1;
        for(int t = x/10; t != 0; t /=10) {
            current_power *= 10;
        }

        int ans = 0;
        int cur = x;
        while(cur) {
            int digit = cur % 10; //[-9, 0]
            if(digit < (INT_MIN - ans)/current_power) {
                return 0;
            }
            
            ans += digit * current_power;
            cur /= 10;
            current_power /= 10;
        }

        if(ans < INT_MIN + 1 && plus) {
            return 0;
        }

        return plus? -ans : ans;
    }
};