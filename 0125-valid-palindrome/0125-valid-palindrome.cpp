class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(auto c: s) {
            if(isalpha(c)) {
                ans += tolower(c);
            } else if(isalnum(c)) {
                ans += c;
            }
        }

        int left = 0, right = ans.length() - 1;
        while(left < right) {
            if(ans[left] != ans[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};