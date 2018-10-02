// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/567/
class Solution {
    public void moveZeroes(int[] nums) {
        int shift = 0; // number of 0s seen
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                shift += 1;
            } else if (shift > 0) {
                nums[i-shift] = nums[i];
                nums[i] = 0;
            }
        }
    }
}