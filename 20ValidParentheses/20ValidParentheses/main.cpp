#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            else {
                if (stack.empty()) {
                    return false;
                }
                char top = stack.top();
                stack.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution solve;
    std::string test = "()";
    bool result = solve.isValid(test);

    if (result) {
        std::cout << "Valid" << std::endl;
    }
    else {
        std::cout << "Invalid" << std::endl;
    }

    return 0;
}