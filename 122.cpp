class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int stock_price = 0; // buying price for last transaction;
        bool have_stock = false;
        int n = prices.size();
        for (int i = 0; i < n; ++i) {
            if (have_stock) {
                if ((i + 1 < n and prices[i+1] < prices[i]) or i == n - 1) {
                    profit += prices[i] - stock_price;
                    have_stock = false; // sell
                }
            } else {
                if (i + 1 < n and prices[i+1] > prices[i]) {
                    stock_price = prices[i];
                    have_stock = true; // buy
                }
            }
        }
        return profit;
    }
};
