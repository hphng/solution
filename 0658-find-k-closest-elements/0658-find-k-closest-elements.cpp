class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [x](int a, int b){
            if(abs(a-x) == abs(b-x)){
                return a < b;
            }
            return abs(a-x) < abs(b-x);
        });
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(arr[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};