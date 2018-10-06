// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        bool match;
        int j = 0;
        for (int i = 0; i < haystack.length(); i++) {
            match = true;
            for (j = 0; j < needle.length(); j++) {
                if (haystack[i+j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }
        return -1;
    }
};
