class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        // If k >= n/2, it becomes unlimited transactions problem
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
            return profit;
        }
        
        // DP arrays: buy[t] = max profit after t-th buy, sell[t] = max profit after t-th sell
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        
        for (int price : prices) {
            for (int t = 1; t <= k; t++) {
                buy[t] = max(buy[t], sell[t - 1] - price);
                sell[t] = max(sell[t], buy[t] + price);
            }
        }
        
        return sell[k];
    }
};
