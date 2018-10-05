// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length(); i++) {
            int solo = 1;
            for (int j = 0; j < s.length(); j++) {
                if (i != j && s[i] == s[j]) {
                    solo = 0;
                    break;
                }
            }
            if (solo) {
                return i;
            }
        }
        return -1;
    }
};
