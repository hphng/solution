class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        for(int i = 0; i < num.length(); i++) {
            char c = num[i];

            while(!s.empty() && s.top() - '0' > c - '0' && k != 0){
                s.pop();
                k--;
            }

            s.push(c);
        }

        while(k > 0 && !s.empty()) {
            s.pop();
            k--;
        }

        string ans = "";
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        int noZeroIndex = 0;
        for(int i = 0; i < ans.length(); i++){
            if(ans[i] == '0'){
                noZeroIndex++;
            } else {
                break;
            }
        }
        ans = ans.substr(noZeroIndex);
        if(ans.empty()) 
            ans = "0";
        return ans;
    }
};