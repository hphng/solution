class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastSeen;
        unordered_map<char, bool> instack;

        for(int i = 0; i < s.length(); i++){
            lastSeen[s[i]] = i;
            instack[s[i]] = false;
        }

        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(instack[s[i]]) {
                continue;
            }

            while(!st.empty() && s[st.top()] > s[i] && lastSeen[s[st.top()]] > i ) {
                instack[s[st.top()]] = false;
                st.pop();
            }

            st.push(i);
            instack[s[i]] = true;
        }

        string ans = "";
        while(!st.empty()) {
            ans += s[st.top()];
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};