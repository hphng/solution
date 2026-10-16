class Solution {
public:
    bool isFit(const vector<int>& weights, int capacity, int targetDays) {
        int count = 0;
        int i = 0;
        int curWeight = 0;
        while(i < weights.size()) {
            if(curWeight + weights[i] > capacity) {
                count++;
                curWeight = weights[i];
            } else {
                curWeight += weights[i];
            }

            i++;
        }
        count++;

        return count <= targetDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;

        for(int i =0; i < weights.size(); i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }

        while(low < high) {
            int mid = low + (high -low)/2;
            if(!isFit(weights, mid, days)) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};