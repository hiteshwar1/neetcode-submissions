class Solution {
   public:
    int helper(string s, int i, vector<int>& dp) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];
        int one = helper(s, i + 1, dp);
        int two = 0;
        if ((i < s.size() - 1) && ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6')))
            two = helper(s, i + 2, dp);
        return dp[i] = one + two;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i + 1];
            if (i + 1 < n &&
                (s[i] == '1' ||
                (s[i] == '2' && s[i + 1] <= '6'))) {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};
