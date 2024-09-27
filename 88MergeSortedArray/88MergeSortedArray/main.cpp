#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int count_m = 0;
        int count_n = 0;
        std::vector<int> result = {};

        while (count_m + count_n != m + n && !nums1.empty() && !nums2.empty() ) {
            if (count_m != m && (count_n == n || nums1[count_m] <= nums2[count_n] )) {
                result.push_back(nums1[count_m]);
                count_m++;
            }
            else if (count_n != n && (nums2[count_n] < nums1[count_m] || count_m == m)) {
                result.push_back(nums2[count_n]);
                count_n++;
            }
        }
        if (!result.empty()) {
            nums1 = result;
        }
   
    }
};

int main() {
    std::vector<int> nums1 = { 1 ,2 ,3 ,0 ,0 ,0 };
    std::vector<int> nums2 = { 2, 5 ,6 };
    int m = 3;
    int n = 3;
    Solution solve;
    solve.merge(nums1, m, nums2, n);
}