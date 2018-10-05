// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/
#include <cmath>
#include <limits.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int negative = 0;
        if (x < 0) {
            negative = 1;
            x = -x;
        }

        // Count the number of digits.
        int x1 = x;
        int digits = 1;
        while (x1 > 9) {
            x1 /= 10;
            digits++;
        }

        // Create a new integer. If overflow occurs, return 0.
        // The calculation of to_add could overflow as well,
        // but it is not checked.
        int result = 0;
        int to_add;
        for (int i = 0; i < digits; i++) {
            to_add = (x % 10) * (pow(10, digits-i-1));
            if (result > INT_MAX - to_add) {
                return 0;
            }
            result += to_add;
            x /= 10;
        }

        if (negative) {
            return -result;
        }
        return result;
    }
};
