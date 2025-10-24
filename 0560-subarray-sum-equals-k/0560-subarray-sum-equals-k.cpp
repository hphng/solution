class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i = 1; i < n+1; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n+1; i++){
            int cur = prefix[i] - k;
            if(mp.find(cur) != mp.end()){
                // ans++;
                ans += mp[cur];
            } 
            mp[prefix[i]]++;
        }
        // for(auto x: prefix){
        //     cout << x << " ";
        // }
        // cout << endl;
        // for(auto pair : mp){
        //     cout << pair.first << " " << pair.second << endl;
        // }
        return ans;
        // 1 1 1
        // 1 2 3
        // 0 1

    }
};