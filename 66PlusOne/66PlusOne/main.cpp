#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int lastDigit = digits.size() - 1;
        bool flag = 0;
        std::stack<int> src;
        std::vector<int> result;
        while (digits[lastDigit] + 1 == 10) {
            digits[lastDigit] = 0;
            src.push(digits[lastDigit]);
            if (lastDigit == 0) {
                src.push(1);
                flag = 1;
                break;
            }
            lastDigit--;
        }
        if (!flag) {
            digits[lastDigit] += 1;
            return digits;
        }
        else {
            while (!src.empty()) {
                result.push_back(src.top());
                src.pop();
            }
            return result;
        }
    }
};

int main() {
    std::vector<int> digits = { 4, 3, 2, 1 };
    Solution solve;
    solve.plusOne(digits);
    for (int item : digits ){
        std::cout << item;
    }

}