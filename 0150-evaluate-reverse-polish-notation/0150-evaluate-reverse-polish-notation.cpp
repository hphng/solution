class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(auto token: tokens) {
            if(!(token == "+" || token == "-" || token == "*" || token == "/")){
                s.push(token);
                continue;
            }

            int second = stoi(s.top());
            s.pop();
            int first = stoi(s.top());
            s.pop();
            int ans;
            if(token == "+"){
                ans = first + second;
            } else if(token == "-") {
                ans = first - second;
            } else if(token == "*") {
                ans = first * second;
            } else {
                ans = first/second;
            }
            s.push(to_string(ans));
        }
        return stoi(s.top());
    }
};