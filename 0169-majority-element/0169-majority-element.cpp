class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x, c = 0;
        for(auto i : nums){
            if(c == 0){
                x = i;
                c ++;
            }else if(x != i){
                c--;
            }else if(x == i){
                c++;
            }
        }
        return x;
    }
};