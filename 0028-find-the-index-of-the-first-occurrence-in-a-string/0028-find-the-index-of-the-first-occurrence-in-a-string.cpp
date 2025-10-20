class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        vector<int> lps (m, 0); //longest proper prefix
        int i = 1, j = 0;
        while(i < m){
            if(needle[i] == needle[j]){
                j++;
                lps[i] = j;
                i++;
            } else {
                if(j > 0){
                    j = lps[j-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        i = 0, j = 0;
        while( i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == m ) return i - j;
            } else if(j > 0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
        return -1;
    }
};