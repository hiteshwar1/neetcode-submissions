class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0;
        int minbuy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minbuy) {
                minbuy = prices[i];
            } else {
                maxpro = max(maxpro, prices[i] - minbuy);
            }
        }
        return maxpro;
    }
};
