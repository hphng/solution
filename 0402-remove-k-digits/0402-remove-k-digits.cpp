class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> st;
        for(int i = 0; i < num.length(); i++){
            if(st.empty()){
                st.push_back(num[i]);
                continue;
            }

            while(!st.empty() && st.back() > num[i] && k > 0){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }

        while(!st.empty() && k--){
            st.pop_back();
        }
 
        while(!st.empty() && st.front() == '0'){
            st.pop_front();
        }

        string ans = "";
        while(!st.empty()){
            char c = st.front();
            ans += c;
            st.pop_front();
        }
        if(ans == "") return "0";
        return ans;
    }
};