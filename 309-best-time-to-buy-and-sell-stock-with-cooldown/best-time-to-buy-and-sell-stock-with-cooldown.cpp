class Solution {
public:
     int t[5001][2];
    int solve(vector<int>& prices, int day, int n, bool buy){
        if(day >= n){
            return 0;
        }

        int profit = 0;

        if(t[day][buy] != -1){
            return t[day][buy];
        }

        if(buy){  // aj buy krna hai ya nhi krna
            int take     = solve(prices, day+1, n, false) - prices[day]; // profite = selling_prices - buying_prices
            int not_take = solve(prices, day+1, n, true); // jab buy nhi kia then next day buy kro
            profit = max({profit, take, not_take});

        } else {
            int sell = prices[day] + solve(prices, day+2, n, true); // jab sell kia hai, tuo ajj k rate k mutabik kuch paise mily hogy +jab  sell krdia hai then app just next day buy nhi kr skty iss liye day+2 likha hai  
            int not_sell = solve(prices, day+1, n, false);

            profit = max({profit, sell, not_sell});
        }

        return t[day][buy] = profit;

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool buy = true;
        memset(t,-1,sizeof(t));
        return solve(prices,0,n,buy);  
    }
};