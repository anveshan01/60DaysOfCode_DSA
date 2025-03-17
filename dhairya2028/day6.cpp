//problem Stock Buy & Sell
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bestbuy = prices[0], maxprofit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] < bestbuy)
                bestbuy = prices[i];
            maxprofit = max(maxprofit, (prices[i] - bestbuy));
        }
        return maxprofit;
    }
};
