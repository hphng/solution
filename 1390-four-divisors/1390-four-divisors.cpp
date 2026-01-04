class Solution {
public:
    int checkDivisor(int x){
        int count = 2;
        int ans = 1 + x;
        int sq = sqrt(x);
        if(sq*sq == x){
            return 0;
        }

        for(int i = 2; i < sqrt(x); i++){
            if(count > 4){
                return 0;
            }

            if(x % i == 0){
                count += 2;
                ans = ans + i + x/i;    
            }
        }

        if(count != 4){
            return 0;
        }

        return ans;
    }
    int sumFourDivisors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int ans = 0;
        for(auto num: nums){
            ans += checkDivisor(num);
        }
        return ans;

    }
};