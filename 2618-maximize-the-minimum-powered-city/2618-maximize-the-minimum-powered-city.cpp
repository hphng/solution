class Solution {
public:
    bool check(vector<long long>& power, int r, int k, long long target){
        int n = power.size();
        vector<long long> add(n, 0);
        long curAdd = 0;
        long used = 0;
        for(int i = 0; i < n; i++){
            if(i > r){
                curAdd -= add[i - r -1];
            }
            if(power[i] + curAdd < target){
                long long need = target - power[i] - curAdd;
                if(need > k - used) return false;
                used += need;
                int index = min(n-1, i + r);
                add[index] += need;
                curAdd += need;
            }
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n+1, 0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = stations[i] + prefix[i];
        }
        vector<long long> power;
        for(int i = 0; i < n; i++){
            int x = max(0, i-r);
            int y = min(n-1, i + r);
            long long total = prefix[y+1] - prefix[x];
            power.push_back(total);
        }

        long long left = 0, right = (long) 1e15;
        while(left < right){
            long long mid = left + (right-left+1)/2;

            if(check(power, r, k, mid)){
                left = mid;
            } else {
                right = mid -1;
            }
        }
        return left;
    }
};