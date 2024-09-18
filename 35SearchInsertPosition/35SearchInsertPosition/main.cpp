#include <iostream>
#include <vector>

class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) {
		int max = nums.size() - 1;
		int min = 0;
		int mid = 0;
		while (max - min > 1) {
			mid = (max + min) / 2;
			if (target < nums[mid]) {
				max = mid;
			}
			else if (target > nums[mid]) {
				min = mid;
			}
			else if (target == nums[mid]) {
				return mid;
			}
		}
		if (target > nums[max]) {
			return max + 1;
		}
		else if (target = nums[mid]) {
			return mid;
		}
		else if (target < nums[min]) {
			return min;
		}
		else {
			return min + 1;
		}
	}
};

int main() {
	//std::vector<int> nums = { 1, 4, 6, 8, 10, 15, 20, 35, 40, 52 };
	std::vector<int> nums = {1};
	Solution solve;
	std::cout << solve.searchInsert(nums, 0) << std::endl;
}