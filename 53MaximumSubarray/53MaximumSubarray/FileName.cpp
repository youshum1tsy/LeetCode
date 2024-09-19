#include <vector>
#include <iostream>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_here = nums[0];
        int max_far = max_here;
        for (int i = 1; i < nums.size(); i++) {
            if (max_here + nums[i] > nums[i]) {
                max_here = max_here + nums[i];
            }
            else {
                max_here = nums[i];
            }
            if (max_far < max_here) {
                max_far = max_here;
            }
            else {
                continue;
            }
        }
        return max_far;
    }
};

int main() {
    Solution solve;
    std::vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    std::cout << solve.maxSubArray(nums) << std::endl;
}