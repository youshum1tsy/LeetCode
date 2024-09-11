#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> result;
        for (size_t i = 0; i < nums1.size(); i++) {
            for (size_t j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    for (size_t c = j; c < nums2.size(); c++) {
                        if (nums2[c] > nums2[j]) {
                            result.push_back(nums2[c]);
                            break;
                        }
                        else if (c == nums2.size() - 1 || c == nums2.size()) {
                            result.push_back(-1);
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solve;
    std::vector<int> nums1 = { 1,3,5,2,4 };
    std::vector<int> nums2 = { 6,5,4,3,2,1,7 };
    std::vector<int> result = solve.nextGreaterElement(nums1, nums2);
    for (int elem : result) {
        std::cout << elem << " ";
    }
}