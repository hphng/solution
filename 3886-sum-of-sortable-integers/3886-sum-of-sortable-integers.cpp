class Solution {
public:
    vector<int> buildlps(vector<int>&  pattern, int start, int len){
        vector<int> lps(len, 0);
        int j = 0;
        for(int i = 1; i < len; i++){
            while(j > 0 && pattern[start+1] != pattern[start+j]){
                j = lps[j-1];
            }

            if(pattern[start+i] == pattern[start+j]){
                j++;
            }

            lps[i] = j;
        }
        return lps;
    }

    bool checkRotate(vector<int>& nums, vector<int>& sorted, int start, int k){
        int j = 0;
        vector<int> lps = buildlps(sorted, start, k);
        for(int i = 0; i < 2*k-1; i++){
            int val = nums[start + (i%k)];

            while(j > 0 && val != sorted[start + j]){
                j = lps[j-1];
            }
            if(val == sorted[start + j]){
                j++;
            }
            if(j == k){
                return true;
            }
        }
        return false;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        vector<int> divisors;
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){
                divisors.push_back(i);
                if(i * i != n){
                    divisors.push_back(n/i);
                }
            }
        }

        int ans = 0;
        for(auto d: divisors){
            bool check = true;
            for(int start = 0; start < n; start += d){
                if(!checkRotate(nums, sorted, start, d)){
                    check = false;
                    break;
                }
            }
            if(check){
                ans += d;
            }
        }
        return ans;
    }
};