class RandomizedSet {
    private:
    vector<int> v;
    unordered_map<int, int> mp; //value - index
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }
        int idx = mp[val];
        int last = v.back();

        v[idx] = last;
        mp[last] = idx;

        v.pop_back();
        mp.erase(val);
        return true; 
    }
    
    int getRandom() {
        int n = v.size();
        int idx = rand() % n;
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */