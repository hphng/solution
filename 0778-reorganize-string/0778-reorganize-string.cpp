class Solution {
public:
    string reorganizeString(string s) {
        if(s.length() <= 1){
            return s;
        }
        priority_queue<pair<int, int>> pq;
        unordered_map<char, int> mp;
        for(auto c : s){
            mp[c]++;
        }

        for(auto pair : mp){
            pq.push({pair.second, pair.first});
        }
        string ans = "";
        while(pq.size() > 1){
            auto one = pq.top();
            pq.pop();
            auto two = pq.top();
            pq.pop();

            ans += one.second;
            ans += two.second;

            if(one.first > 1){
                pq.push({one.first -1 , one.second});
            }
            if(two.first > 1){
                pq.push({two.first-1, two.second});
            }
        }

        if(pq.empty()){
            return ans;
        }

        auto last = pq.top();
        if((!ans.empty() && ans.back() == last.second) || last.first > 1){
            return "";
        }
        ans += last.second;
        return ans;
    }
};