class Solution {
    public int[] plusOne(int[] digits) {
        int[] result = digits;
        for (int i = 0; i < digits.length; i++) {
            digits[digits.length-1-i] += 1;
            if (digits[digits.length-1-i] < 10) {
                break;
            }
            digits[digits.length-1-i] = 0;
        }
        if (digits[0] == 0) {
            result = new int[digits.length+1];
            result[0] = 1;
            for (int i = 1; i < digits.length; i++) {
                result[i] = 0;
            }
        }
        return result;
    }
}