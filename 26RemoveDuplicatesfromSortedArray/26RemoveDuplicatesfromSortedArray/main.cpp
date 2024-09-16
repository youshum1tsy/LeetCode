#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int replace = 0;
        int count = 1;
        for (int current = 0; current < nums.size(); current++) {

            if (nums[current] != nums[replace]) {
                replace++;
                count++;
                nums[replace] = nums[current];
            }
        }
        return count;
    }
};

int main() {
    std::vector<int> nums = {1,1,2};
    Solution solve;
    int size = solve.removeDuplicates(nums);
    for (int i = 0; i < size; i++) {
        std::cout << nums[i] << " ";
    }
    return 0;
}