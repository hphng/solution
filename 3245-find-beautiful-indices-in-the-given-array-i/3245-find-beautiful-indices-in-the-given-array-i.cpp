class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ans;
        int apos = s.find(a);
        int bpos = s.find(b);
        int n = s.length();
        while(apos != string::npos && bpos != string::npos){
            if(abs(apos - bpos) > k){
                if(apos < bpos){
                    apos = s.find(a, apos+1);
                } else {
                    bpos = s.find(b, bpos+1);
                }
            } else {
                ans.push_back(apos);
                apos = s.find(a, apos+1);
            }
        }
        return ans;
    }
};