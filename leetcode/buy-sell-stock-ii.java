class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        int prev = prices[0];
        int start = prices[0];
        int profit = 0;
        boolean rising = false;
        for (int i = 0; i < prices.length; i++) {
            if (rising && prices[i] < prev) {
                profit += prev - start;
                rising = false;
            } else if (!rising && prices[i] > prev) {
                start = prev;
                rising = true;
            }
            prev = prices[i];
        }
        if (rising) {
            profit += prev - start;
        }
        return profit;
    }
}
