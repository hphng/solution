class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> count;

        for(char c: jewels) {
            count.insert(c);
        }

        int ans = 0;
        for(char c: stones) {
            if(count.count(c)) {
                ans++;
            }
        }
        return ans;
    }
};