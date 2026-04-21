class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0], maxPro = 0;
        for(int i = 1; i < prices.size(); i++){
            if(minBuy > prices[i]) minBuy = prices[i];
            else maxPro = max(maxPro, prices[i] - minBuy);
        }
        return maxPro;
    }
};
