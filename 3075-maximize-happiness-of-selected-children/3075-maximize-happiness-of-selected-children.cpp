class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), [](const auto& p, const auto& q){
            return p > q;
        });

        int n = happiness.size();
        long long ans = 0;
        for(int i = 0; i < k; i++){
            long long selected = happiness[i] - i;
            selected = max(0LL, selected);
            ans += selected;
            if(selected == 0){
                break;
            }
        }
        return ans;
    }
};