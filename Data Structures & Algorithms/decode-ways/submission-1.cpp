class Solution {
   public:
    int helper(string s, int i, vector<int>& dp) {
        if (s[i] == '0') return 0;
        if (i >= s.size()) return 1;
        if (dp[i] != -1) return dp[i];
        int one = helper(s, i + 1, dp);
        int two = 0;
        if (i < s.size() - 1) {
            if(s[i] == '1' || s[i] == '2' && s[i+1] < '7') two = helper(s, i + 2, dp);
        }
        return dp[i] = one + two;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return helper(s, 0, dp);
    }
};
