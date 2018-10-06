// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string("");
        }
        char match; // character to check against
        // Explanation of the condition:
        // If there is a string shorter than strs[0],
        // there will be a mismatch at the shorter
        // string's null terminator. If there is a
        // string longer than strs[0], then the next
        // character would mismatch so breaking out
        // of the loop is fine.
        for (int idx = 0; idx < strs[0].length(); idx++) {
            match = strs[0][idx];
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][idx] != match) {
                    return strs[0].substr(0, idx);
                }
            }
        }
        return strs[0];
    }
};
