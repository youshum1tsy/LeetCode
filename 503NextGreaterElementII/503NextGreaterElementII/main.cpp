#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> result(size, -1);
        std::stack<int> s;

        for (int i = 0; i < 2 * size; ++i) {
            int currentIndex = i % size;
            while (!s.empty() && nums[s.top()] < nums[currentIndex]) {
                result[s.top()] = nums[currentIndex];
                s.pop();
            }
            if (i < size) {
                s.push(currentIndex);
            }
        }
        return result;
    }
};
int main() {
    Solution solve;
    std::vector<int> nums = { 1, 2, 3, 4, 5 };
    std::vector<int> result = solve.nextGreaterElements(nums);
    for (int elem : result) {
      std::cout << elem << " ";
    }
}