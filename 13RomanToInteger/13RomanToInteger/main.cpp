#include <iostream>
#include <map>

class Solution {
public:

    int romanToInt(std::string s) {
        std::map<char, int> romanNumbers = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
        int result = 0;
        for (int i = 0; i < s.size(); i++ ) {
            if (s[i] == 'I') {
                if (s[i+1] == 'V') {
                    result = result + 4;
                }
                else if (s[i+1] == 'X') {
                    result = result + 9;
                }
            }
            else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    result = result + 40;
                }
                else if (s[i + 1] == 'C') {
                    result = result + 90;
                }
            }
            else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {
                    result = result + 400;
                }
                else if (s[i + 1] == 'M') {
                    result = result + 900;
                }
            }
            result = result + romanNumbers[s[i]];
        }
    }
};

int main() {
    std::string s1 = "III";
    std::string s2 = "LVIII";
    std::string s3 = "MCMXCIV";
    Solution solve;
    std::cout << solve.romanToInt(s1) << std::endl;
    std::cout << solve.romanToInt(s2) << std::endl;
    std::cout << solve.romanToInt(s3) << std::endl;


}