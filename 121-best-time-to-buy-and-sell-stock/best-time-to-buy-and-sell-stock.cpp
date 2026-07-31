class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      if(n == 0) return 0;

      int buyPrice = prices[0];
      int maxProfit = 0;

      for(int i = 0; i < n ;i++){
         if(prices[i] < buyPrice){
            buyPrice = prices[i];
         }

         int profit = prices[i] - buyPrice;

          maxProfit = max(maxProfit,profit);
      }
      return maxProfit;

    }
};
