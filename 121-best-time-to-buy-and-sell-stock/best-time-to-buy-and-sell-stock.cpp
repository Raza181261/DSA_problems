class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;

        int maxP = 0;

        while(right < prices.size()){
          if(prices[left] < prices[right]){
            int profit = prices[right] - prices[left];
            maxP = max(maxP , profit);
         }else{
            left = right;
            
          }
            right++;
        }
        return maxP;
    }
};