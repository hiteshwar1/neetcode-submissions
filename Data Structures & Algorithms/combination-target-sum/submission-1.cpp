class Solution {
   public:
    void helper(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& tmp, int i) {
        if (i >= nums.size() || target < 0) return;
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        for (int x = i; x < nums.size(); x++) {
            if (target >= nums[x]) {
                tmp.push_back(nums[x]);
                helper(nums, target - nums[x], res, tmp, x);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(nums, target, res, tmp, 0);
        return res;
    }
};
