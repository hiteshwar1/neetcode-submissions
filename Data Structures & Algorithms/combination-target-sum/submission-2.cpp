class Solution {
   public:
    void helper(vector<int>& nums, int target, int i, vector<vector<int>>& res, vector<int> arr) {
        if (i >= nums.size() || target < 0) return;
        if (target == 0) {
            res.push_back(arr);
            return;
        }

        for (int x = i; x < nums.size(); x++) {
            if (nums[x] <= target) {
                arr.push_back(nums[x]);
                helper(nums, target - nums[x], x, res, arr);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        helper(nums, target, 0, res, arr);
        return res;
    }
};
