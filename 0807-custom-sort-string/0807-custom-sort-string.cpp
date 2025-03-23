class Solution {
private:
    unordered_map<char, int> mp;
public:
    string customSortString(string order, string s) {
        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }
        sort(s.begin(), s.end(), [&](char x, char y){
            int a = 201, b = 201;
            if(mp.find(x) != mp.end()){
                a = mp[x];
            }
            if(mp.find(y) != mp.end()){
                b = mp[y];
            }
            return a < b;
        });
        return s;
    }
};