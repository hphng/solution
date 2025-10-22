struct comp {
        bool operator() (pair<int, string> p1, pair<int, string> p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto word : words){
            mp[word]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(auto pair: mp){
            pq.push({pair.second, pair.first});
        }

        int i = k;
        vector<string> ans;
        while(i-- > 0){
            auto cur = pq.top();
            pq.pop();
            ans.push_back(cur.second);
        }
        return ans;
    }
};