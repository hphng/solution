class Solution {
public:
    int roundUp(int x, int y){
        if(x % y == 0){
            return x / y;
        }
        return (x/y + 1);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size() > h) {
            return -1;
        }

        int left = 1, right = 0;
        for(int i = 0; i < piles.size(); i++){
            right = max(right, piles[i]);
        }

        int mid = left + (right - left)/2;
        while(left <= right){
            mid = (left + right)/2;
            cout << mid << endl;
            long long curHour = 0;
            for(int i = 0; i < piles.size(); i++){
                curHour = curHour + roundUp(piles[i], mid);
            }
            if(curHour <=h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
        // int curHour = 0;
        // for(int i = 0; i < piles.size(); i++){
        //     curHour = curHour + roundUp(piles[i], mid);
        // }
        // if(curHour == h){
        //     return mid;
        // }
        // return mid + 1;
    }
};