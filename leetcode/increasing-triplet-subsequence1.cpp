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
        buf[0] = nums[0];
        int buf_idx = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (buf_idx == 0) {
                if (nums[i] < buf[0]) {
                    buf[0] = nums[i];
                } else if (buf[0] < nums[i]) {
                    buf[1] = nums[i];
                    buf_idx++;
                }
            } else {
                if (nums[i] < buf[0]) {
                    buf[0] = nums[i];
                } else if (buf[0] < nums[i] && nums[i] < buf[1]) {
                    buf[1] = nums[i];
                } else if (buf[1] < nums[i]) {
                    return true;
                }
            }
        }

        return false;
    }
};