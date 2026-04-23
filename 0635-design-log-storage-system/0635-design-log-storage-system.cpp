class LogSystem {
private:

    unordered_map<string, int> split;
    multimap<string, int> logs;
public:
    LogSystem() {
        split["Year"] = 4;
        split["Month"] = 7;
        split["Day"] = 10;
        split["Hour"] = 13;
        split["Minute"] = 16;
        split["Second"] = 19;
    }
    
    void put(int id, string timestamp) {
        logs.insert({timestamp, id});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        int len = split[granularity];
        string left = start.substr(0, len);
        string right = end.substr(0, len);

        vector<int> ans;
        auto point = logs.lower_bound(left);
        for(auto it = point; it != logs.end() && it -> first.substr(0, len) <= right; it++) {
            ans.push_back(it -> second);
        } 
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */