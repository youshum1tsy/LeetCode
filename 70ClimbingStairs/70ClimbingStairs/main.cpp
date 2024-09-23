#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if ( n <= 2) {
            return n;
        }

        int prev1 = 1;
        int prev2 = 2;
        int current = 0;

        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        return current;
    }
};

int main() {
    Solution solve;
    std::cout << solve.climbStairs(20) << std::endl;

}