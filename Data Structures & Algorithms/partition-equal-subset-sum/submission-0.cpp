class Solution {
   public:
    bool helper(vector<int>& nums, int sum, int i, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (i == 0) return sum == nums[i];
        if (dp[i][sum] != -1) return dp[i][sum];
        bool notpick = helper(nums, sum, i - 1, dp);
        bool pick = false;
        if (sum >= nums[i]) pick = helper(nums, sum - nums[i], i - 1, dp);
        return dp[i][sum] = pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum % 2 != 0) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
        return helper(nums, sum / 2, nums.size() - 1, dp);
    }
};
