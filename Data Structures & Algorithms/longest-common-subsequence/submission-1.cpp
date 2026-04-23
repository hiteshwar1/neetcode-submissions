class Solution {
   public:
    int helper(string s, string t, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i - 1] == t[j - 1]) return dp[i][j] = 1 + helper(s, t, i - 1, j - 1, dp);
        return dp[i][j] = max(helper(s, t, i - 1, j, dp), helper(s, t, i, j - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        for (int i = 0; i <= text1.size(); i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= text2.size(); i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[text1.size()][text2.size()];
    }
};
