class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> prefix(arr.size() + 1, 0);
        for(int i = 1 ; i < prefix.size(); i++){
            prefix[i] = prefix[i-1] + arr[i-1];
        }
        int odd = 0, even = 0;
        for(auto sum : prefix){
            if(sum % 2 == 0){
                even++;
            } else {
                odd++;
            }
        }
        int mod = 1e9 + 7;
        long long ans = (long long) odd * even % mod;
        return int(ans);
    }
};