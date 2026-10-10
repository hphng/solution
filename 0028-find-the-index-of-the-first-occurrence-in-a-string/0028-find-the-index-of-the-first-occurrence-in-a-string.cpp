class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;
        while (i < n) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int textIndex = 0;
        int patternIndex = 0;
        vector<int> matches;
        while (textIndex < m) {                       // CHANGED: only the haystack bounds the loop
            if (haystack[textIndex] == needle[patternIndex]) {
                textIndex++;
                patternIndex++;

                if (patternIndex == n) {              // MOVED: check for full match right away
                    matches.push_back(textIndex - n);
                    patternIndex = lps[patternIndex - 1];
                }
                continue;
            }

            // here we know haystack[textIndex] != needle[patternIndex]
            if (patternIndex != 0) {                  // CHANGED: removed the textIndex < n check
                patternIndex = lps[patternIndex - 1];
            } else {
                textIndex++;
            }
        }

        if (matches.size() == 0) return -1;
        return matches[0];
    }
};