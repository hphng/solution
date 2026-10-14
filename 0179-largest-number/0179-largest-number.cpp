class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto num: nums) {
            v.push_back(to_string(num));
        }

        sort(v.begin(), v.end(), [](string a, string b) {
            return a + b > b + a;
        });
        if(v[0] == "0") return "0";
        string ans;
        for(auto s: v){
            ans += s;
        }

        return ans;
    }
};