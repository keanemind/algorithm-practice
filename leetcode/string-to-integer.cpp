// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/
#include <string>
#include <cmath>
#include <limits.h>
#include <cerrno>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;

        // Seek past whitespace
        while (str[i] == ' ') {
            i++;
        }

        // Build integer
        bool negative = false;  
        if (str[i] == '-') {
            negative = true;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        int nums_start = i;
        int digits = 0;
        while (isNumChar(str[i])) {
            digits++;
            i++;
        }
        int res = 0;
        int weight;
        for (int j = 0; j < digits; j++) {
            weight = pow(10, digits-1-j);
            if (
                errno == ERANGE ||
                str[nums_start+j] - 48 > INT_MAX / weight ||
                res > INT_MAX - ((str[nums_start+j] - 48) * weight)
            ) {
                if (negative) {
                    return INT_MIN;
                }
                return INT_MAX;
            }
            res += (str[nums_start+j] - 48) * weight;
        }
        if (negative) {
            return -res;
        }
        return res;
    }

    bool isNumChar(char c) {
        return (48 <= c && c <= 57);
    }
};
