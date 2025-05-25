//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
    public int maxProfit(int[] prices) {
        int min = prices[0];
        int profit = 0;
        for(int i=1;i<prices.length; i++){
            int cost = prices[i]-min;
            profit= Math.max(cost,profit);
            min=Math.min(min,prices[i]);
        }
        return profit;
    }
}