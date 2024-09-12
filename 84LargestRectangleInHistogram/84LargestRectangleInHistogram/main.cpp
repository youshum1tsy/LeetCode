#include <stack>
#include <iostream>
#include <vector>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int current;
        int result = 0;
        int size = heights.size() - 1;
        while (size != 0) {
            current = heights.back();
            heights.pop_back();
            if (current > result) {
                result = current;
            }
            else if (heights.back() > result) {
                result = current;
            }

            if (current > heights.back()) {
                if (heights.back() * 2 >= result) {
                    result = heights.back() * 2;
                }
            }
            else {
                if (current * 2 >= result) {
                    result = current * 2;
                }
            }
            size--;
        }
        return result;
    }
};

int main() {
    std::vector<int> heights = { 9, 0 };
    Solution solve;
    solve.largestRectangleArea(heights);
}