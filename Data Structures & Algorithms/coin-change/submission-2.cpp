class Solution {
   public:
    int helper(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % coins[i] == 0) return amount / coins[i];
            else return 1e9;
        }
        if (i < 0) return 1e9;
        if (dp[i][amount] != -1) return dp[i][amount];
        int notpick = helper(coins, amount, i - 1, dp);
        int pick = 1e9;
        if (amount >= coins[i]) pick = 1 + helper(coins, amount - coins[i], i, dp);
        return dp[i][amount] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 1) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return -1;
        }
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return helper(coins, amount, coins.size() - 1, dp);
    }
};
