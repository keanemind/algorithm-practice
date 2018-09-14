#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int i = 1;
        int j = 1;
        int last;
        while (true) {
            last = nums[j];
            while (j < nums.size() && nums[j] == last) {
                j++;
            }
            if (j == nums.size()) {
                return i+1;
            }
            // j now points to next number
            nums[i] = nums[j];
            i++;
        }
    }
};
