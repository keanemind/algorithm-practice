// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string num = "1";
        string newnum;
        for (int i = 1; i < n; i++) {
            newnum = string();
            int j = 0; // total chars seen
            int count; // count of current char
            char c; // current char
            while (j < num.length()) {
                count = 0;
                c = num[j];
                while (num[j] == c) {
                    count++;
                    j++;
                }
                newnum += count + 48; // quantity
                newnum += c; // value
            }
            num = newnum;
        }
        return num;
    }
};
