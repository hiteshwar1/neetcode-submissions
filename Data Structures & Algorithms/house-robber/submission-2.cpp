class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[nums.size() - 1];
    }
};
