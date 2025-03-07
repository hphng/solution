class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(1e6+2, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i < isPrime.size(); i++){
            if(!isPrime[i]){
                continue;
            }
            for(int j = i* 2; j < isPrime.size(); j += i){
                isPrime[j] = false;
            }
        }
        // for(int i = left; i <=right; i++){
        //     cout << isPrime[i] << " ";
        // }
        vector<int> prime;
        for(int i = left; i <= right; i++){
            if(isPrime[i]){
                prime.push_back(i);
                // cout << i << endl;
            }
        }

        if(prime.size() < 2){
            return {-1, -1};
        }

        vector<int> ans;
        int diff = INT_MAX;
        for(int i = 1; i< prime.size(); i ++){
            if(prime[i] - prime[i-1] < diff){
                diff = prime[i] - prime[i-1];
                ans = {prime[i-1], prime[i]};
            }
        }

        if(ans.size() < 2){
            return {-1, -1};
        }
        return ans;
    }
};