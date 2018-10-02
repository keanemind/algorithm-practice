// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int temp;
        int count = 0;
        for (int i = 0; i < k; i++) {
            temp = nums[nums.size()-i-1];
            int j = nums.size()-i-1;
            while (true) {
                int next = j - k;
                if (next < 0) {
                    next = nums.size() + next;
                }
                nums[j] = nums[next];
                count++;
                if (next == nums.size()-i-1) {
                    break;
                }
                j = next;
            }
            nums[j] = temp;

            /*
            for (int j = 0; j < nums.size(); j++) {
                printf("%d ", nums[j]);
            }
            printf("\n");
            */
            
            if (count == nums.size()) {
                return;
            }
        }
    }
};
