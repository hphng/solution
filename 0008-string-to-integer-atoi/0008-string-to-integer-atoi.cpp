class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        while(index < s.length() && s[index] == ' ') {
            index++;
        }

        if(index == s.length()){
            return 0;
        }
        
        int sign = 1;
        if(s[index] == '-') {
            sign = -1;
            index++;
        } else if(s[index] == '+') {
            sign = 1;
            index++;
        }

        int ans = 0;
        while(index < s.length() && isdigit(s[index])) {
            int digit = s[index] - '0';

            //ans = sign *(ans * 10 + digit) > INT_MAX
            if(ans > (INT_MAX - digit)/10){
                return sign == 1? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            index++;
        }

        return ans * sign;
    }
};