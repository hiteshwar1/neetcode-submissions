class Solution {
   public:
    int helper(vector<int>& nums, int i, vector<int>& dp) {
        if (i == 0) return nums[i];
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];
        int notpick = helper(nums, i - 1, dp);
        int pick = nums[i] + helper(nums, i - 2, dp);
        return dp[i] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) x.push_back(nums[i]);
            if (i != nums.size() - 1) y.push_back(nums[i]);
        }
        vector<int> dpx(x.size(), -1);
        vector<int> dpy(y.size(), -1);
        return max(helper(x, x.size() - 1, dpx), helper(y, y.size() - 1, dpy));
    }
};
