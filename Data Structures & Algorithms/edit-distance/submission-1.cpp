class Solution {
   public:
    int helper(string s, string t, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 0;
        if (i != 0 && j == 0) return i;
        if (i == 0 && j != 0) return j;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i - 1] == t[j - 1]) return dp[i][j] = helper(s, t, i - 1, j - 1, dp);
        int insert = 1 + helper(s, t, i, j - 1, dp);
        int del = 1 + helper(s, t, i - 1, j, dp);
        int replace = 1 + helper(s, t, i - 1, j - 1, dp);
        return dp[i][j] = min(insert, min(del, replace));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return helper(word1, word2, word1.size(), word2.size(), dp);
    }
};
