class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0;
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'W'){
                cnt++;
            }
        }

        int ans = cnt;
        for(int i = k; i < blocks.size(); i++){
            if(blocks[i - k ] == 'W'){
                cnt--;
            }
            if(blocks[i] == 'W'){
                cnt++;
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};