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
        return helper(text1, text2, text1.size(), text2.size(), dp);
    }
};
