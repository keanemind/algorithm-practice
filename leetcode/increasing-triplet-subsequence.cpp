// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/781/
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }

        int buf[3];
        int buf2[2];
        int buf_idx = 0;
        int buf2_idx = 0;
        buf[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (buf_idx == 0) {
                if (nums[i] <= buf[0]) {
                    buf[0] = nums[i];
                } else {
                    buf[1] = nums[i];
                    buf_idx++;
                }
            } else if (buf_idx == 1) {
                if (nums[i] < buf[1]) {
                    if (buf2_idx == 0) {
                        buf2[0] = nums[i];
                        buf2_idx++;
                    } else if (buf2_idx == 1) {
                        if (nums[i] > buf2[0]) {
                            buf2[1] = nums[i];

                            if (buf2[0] > buf[0]) {
                                return true;
                            }
                            buf[0] = buf2[0];
                            buf[1] = buf2[1];
                            buf_idx = 1;
                            buf2_idx = 0;
                        } else {
                            buf2[0] = nums[i];
                            buf2_idx = 0;
                        }
                    }
                } else if (nums[i] > buf[1]) {
                    return true;
                }
            }
        }
        return false;
    }
};
