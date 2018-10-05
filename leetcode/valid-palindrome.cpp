// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (!isAlphanumeric(s[i])) {
                i++;
                continue;
            } else if (!isAlphanumeric(s[j])) {
                j--;
                continue;
            } else if (lower(s[i]) != lower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool isAlphanumeric(char c) {
        return (48 <= c && c <= 57) ||
               (65 <= c && c <= 90) ||
               (97 <= c && c <= 122);
    }

    char lower(char c) {
        if (65 <= c && c <= 90) {
            return c + 32;
        }
        return c;
    }
};
