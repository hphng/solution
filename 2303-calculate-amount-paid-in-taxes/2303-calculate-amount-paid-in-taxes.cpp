class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        
        int n = brackets.size();
        tax = tax + min(income, brackets[0][0]) * brackets[0][1]/100.0;
        int i = 1;
        while(i < n && income > brackets[i-1][0]){
            int window = min(income, brackets[i][0]) - brackets[i-1][0];
            
            tax = tax + window * brackets[i][1]/100.0;
            i++;
        }
        return tax;
    }
};