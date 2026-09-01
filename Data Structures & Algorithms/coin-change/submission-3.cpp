class Solution {
   public:
    int helper(vector<int>& coins, int amt, int i, vector<vector<int>>& dp) {
        if (amt == 0) return 0;
        if (i == 0) {
            if (amt % coins[i] == 0)
                return amt / coins[i];
            else
                return 1e9;
        }
        if (dp[i][amt] != -1) return dp[i][amt];
        int notpick = helper(coins, amt, i - 1, dp);
        int pick = 1e9;
        if (amt >= coins[i]) pick = 1 + helper(coins, amt - coins[i], i, dp);
        return dp[i][amt] = min(pick, notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = helper(coins, amount, coins.size() - 1, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
