class Solution {
public:
    void f(vector<int>& nums, int target, vector<vector<int>> &res, vector<int> arr, int curr){
        if(curr >= nums.size() || target < 0) return;
        if(target == 0){
            res.push_back(arr);
            return;
        }
        f(nums, target, res, arr, curr + 1);
        arr.push_back(nums[curr]);
        f(nums, target - nums[curr], res, arr, curr);
        arr.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> arr;
        f(nums, target, res, arr, 0);
        return res;
    }
};
