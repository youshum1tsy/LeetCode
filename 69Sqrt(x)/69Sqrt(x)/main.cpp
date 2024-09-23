#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = 46341;
        if (x == 1) {
            return 1;
        }
        while (end - start != 1) {
            int mid = (start + end) / 2;
            if (mid * mid > x) {
                end = mid;
            }
            else if (mid * mid < x) {
                start = mid;
            }
            else if (mid * mid == x) {
                return mid;
            }
        }
        return start;

    }
};

int main() {
    int number = 1;
    Solution solve;
    std::cout << solve.mySqrt(number);
}