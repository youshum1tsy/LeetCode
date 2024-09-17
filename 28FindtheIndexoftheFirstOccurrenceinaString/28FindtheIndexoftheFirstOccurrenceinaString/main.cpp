#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty()) return 0;

        for (int i = 0; i <= (int)haystack.length() - (int)needle.length(); i++) {
            bool match = true;
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }

        return -1;
    }
};

int main() {
    Solution solve;

    std::string haystack = "aaaa";
    std::string needle = "aaa";
    std::cout << solve.strStr(haystack, needle) << std::endl;

    haystack = "sadbutsad";
    needle = "sad";
    std::cout << solve.strStr(haystack, needle) << std::endl;
}