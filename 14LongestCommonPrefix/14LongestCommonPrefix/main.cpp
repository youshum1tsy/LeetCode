#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string result = "";
        std::string last_str = "";
        std::string max_prefix = "";
        int size = strs.size();
        int i = 0;
        int letter = 1;
        bool flag = 0;
        if (strs.size() == 1) {
            return strs[0];
        }

        while (!flag) {
            last_str = strs[i].substr(0, letter);
            i++;
            if (last_str == "") {
                return max_prefix;
            }
            while (i < size) {
                result = strs[i].substr(0, letter);
                if (result != last_str || letter > strs[i].size()) {
                    flag = 1;
                    break;
                }
                i++;
                last_str = result;
            }
            if (!flag) {
                max_prefix = result;
            }
            letter++;
            i = 0;
        }
        return max_prefix;
    }
};

int main() {
    Solution solve;
    std::vector<std::string> str1 = { "flower","flower","flower","flower" };
    std::vector<std::string> str2 = { "dog","racecar","car" };
    std::vector<std::string> str3 = {"",""};
    std::cout << solve.longestCommonPrefix(str1) << std::endl;
}