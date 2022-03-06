class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if (N <= 1) return 0;
        
        int noStock = 0;
		int inHand = -prices[0];
		int Sell = 0;
        
		for (int i = 1; i < N; i++) {
            int tmp = inHand;
            inHand = max(inHand, noStock - prices[i]);
            noStock = max(noStock, Sell);
            Sell = inHand + prices[i];
		}
        
		return max(noStock, Sell);
    }
};