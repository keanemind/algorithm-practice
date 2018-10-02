// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};
