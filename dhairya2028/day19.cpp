//PROBLEM 52 LEETCODE
#include <string>
#include <cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }

        string cleanedString;
        for (char c : s) {
            if (isalnum(c)) {
                cleanedString += std::tolower(c);
            }
        }

        int left = 0;
        int right = cleanedString.length() - 1;

        while (left < right) {
            if (cleanedString[left] != cleanedString[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
