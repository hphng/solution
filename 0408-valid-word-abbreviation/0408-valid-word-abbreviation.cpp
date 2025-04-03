class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        int n = 0;
        while(i < abbr.length() && j < word.length()){
            if(!isdigit(abbr[i])){
                j+=n;
                // cout << abbr[i] << " " << word[j] << endl;
                if(abbr[i] != word[j]){
                    return false;
                }
                n = 0;
                i++;
                j++;
            } else {
                int digit = abbr[i] - '0';
                if(n == 0 && digit == 0){
                    return false;
                }
                n = n*10 + digit;
                i++;
            }
        }
        if(n != 0 ){
            j += n;
        }
        if(i != abbr.length() || j != word.length()){
            return false;
        }
        return true;
        
    }
}; 