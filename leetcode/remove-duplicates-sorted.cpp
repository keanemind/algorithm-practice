#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        int i = 1;
        int j = 1;
        int last;
        if (nums[1] != nums[0]) {
            i = 2;
        }
        while (true) {
            last = nums[j];
            while (j < nums.size() && nums[j] == last) {
                j++;
            }
            if (j == nums.size()) {
                return i; // i starts at 1
            }
            // j now points to next number
            nums[i] = nums[j];
            i++;
        }
    }
};
