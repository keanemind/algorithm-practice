// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        char temp;
        for (int i = 0; i < s.length() / 2; i++) {
            temp = s[i];
            s[i] = s[s.length()-1-i];
            s[s.length()-1-i] = temp;
        }
        return s;
    }
};
