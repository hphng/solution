class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans(n, 0);
        int m = 1;
        for(int i = n-1; i >= 0; i--){
            int cur = digits[i] + m;
            if(cur > 9){
                digits[i] = cur - 10;
                m = 1;
            } else {
                digits[i] = cur;
                m = 0;
            }
        }

        if(m == 1){
            ans.resize(n+1, 0);
            ans[0] = 1;
            for(int i = 0; i < n; i++){
                ans[i+1] = digits[i];
            }
            return ans;
        }

        for(int i = 0; i < n; i++){
            ans[i] = digits[i];
        }
        return ans;

    }
};