class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '(' && s[i] != ')'){
                continue;
            }

            if(st.empty()){
                st.push({s[i], i});
                continue;
            }
            auto [c, index] = st.top();
            if(s[i] == ')' && c == '('){
                st.pop();
            } else {
                st.push({s[i], i});
            }
        }
        while(!st.empty()){
            auto [c, index] = st.top();
            st.pop();
            s[index] = '*';
        }

        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*'){
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};