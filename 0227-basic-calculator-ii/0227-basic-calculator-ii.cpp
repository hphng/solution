class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        s += '+';
        char op = '+';
        int n = 0;
        for(auto& c: s){
            if(c == ' '){
                continue;
            }
            if(isdigit(c)){
                n = n*10 + (c-'0');
                continue;
            }

            if(op == '+'){
                st.push(n);
            } else if(op == '-'){
                st.push(-n);
            } else if(op == '*'){
                int top = st.top();
                st.pop();
                st.push(n* top);
            } else if(op == '/'){
                int top = st.top();
                st.pop();
                st.push(top/n);
            }
            n = 0;
            op = c;
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};