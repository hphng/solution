class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;

        for(int i = 0; i < num.length(); i++){
            if(s.empty()){
                s.push(num[i]);
                continue;
            }

            while(!s.empty() && s.top() > num[i] && k > 0){
                s.pop();
                k--;
            }

            s.push(num[i]);
        }
        while(!s.empty() && k > 0){
            s.pop();
            k--;
        }
        string ans;
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        if(ans.empty()) return "0";
        return ans;
    }
};