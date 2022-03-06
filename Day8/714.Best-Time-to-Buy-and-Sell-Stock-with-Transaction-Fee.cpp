class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            sell = max(sell, hold + prices[i] - fee);
            hold = max(hold, sell - prices[i]);
        }
        return sell;
    }
};