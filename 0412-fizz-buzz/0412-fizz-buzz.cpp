class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for (int x = 1; x <= n; x++) {
            if (x % 3 == 0 && x % 5 == 0)
                v.push_back("FizzBuzz");
            else if (x % 3 == 0)
                v.push_back("Fizz");
            else if (x % 5 == 0)
                v.push_back("Buzz");
            else
                v.push_back(to_string(x));
        }
        return v;
    }
};