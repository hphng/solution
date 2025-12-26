class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        int n = customers.length();
        //assume open everyday
        for(int i = 0; i < n; i++){
            if(customers[i] == 'N'){
                penalty++;
            }
        }
        int x = penalty;
        int bestTime = n;
        for(int i = n-1; i >= 0; i--){
            // int x = penalty;
            if(customers[i] == 'Y'){
                x++;
            }

            if(customers[i] == 'N'){
                x--;
            }
            // cout << i << " " << x << endl;
            if(x <= penalty){
                penalty = x;
                bestTime = i;
            }
        }
        return bestTime;
    }
};