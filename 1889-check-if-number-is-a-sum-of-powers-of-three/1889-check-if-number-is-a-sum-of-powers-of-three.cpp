class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 0){
            if(n % 3 == 1){
                n = (n-1)/3;
            } else if(n % 3 == 0){
                n = n/3;
            } else {
                return false;
            }
            // cout << n << endl;
        }
        if(n == 0){
            return true;
        }
        return false;
    }
};