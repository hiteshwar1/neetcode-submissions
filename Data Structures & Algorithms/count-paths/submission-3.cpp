class Solution {
   public:
    int helper(int m, int n, vector<vector<int>>& dp) {
        if (m < 0 || n < 0) return 0;
        if (m == 0 && n == 0) return 1;
        if (dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
