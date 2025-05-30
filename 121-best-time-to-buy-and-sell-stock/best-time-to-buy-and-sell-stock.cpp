class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxPrice = 0;

        for(int price:prices){
            if(price<minPrice){
                minPrice = price;
            } else {
                int profit =price - minPrice;
                maxPrice = max(maxPrice,profit);
            }
        }
        return maxPrice;
    }
};