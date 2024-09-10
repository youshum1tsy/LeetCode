#include <iostream>
#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> numbers;
        int first;
        int second;

        for (const auto& token : tokens) {
            if (token == "+") {
                second = numbers.top();
                numbers.pop();
                first = numbers.top();
                numbers.pop();
                numbers.push(first + second);
            }
            else if (token == "-") {
                second = numbers.top();
                numbers.pop();
                first = numbers.top();
                numbers.pop();
                numbers.push(first - second);
            }
            else if (token == "*") {
                second = numbers.top();
                numbers.pop();
                first = numbers.top();
                numbers.pop();
                numbers.push(first * second);
            }
            else if (token == "/") {
                second = numbers.top();
                numbers.pop();
                first = numbers.top();
                numbers.pop();
                numbers.push(first / second);
            }
            else {
                numbers.push(std::stoi(token));
            }
        }

        return numbers.top();
    }
};

int main() {
    Solution solve;
    std::vector<std::string> tokens = { "3","11","+","5","-" };
    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result = solve.evalRPN(tokens);
    std::cout << "Result: " << result << std::endl;
    tokens = { "2","1","+","3","*" };
    result = solve.evalRPN(tokens);
    std::cout << "Result: " << result << std::endl;
}