class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_left = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < min_left) min_left = prices[i];
            else profit = max(profit, prices[i] - min_left);
        }
        return profit;
    }
};