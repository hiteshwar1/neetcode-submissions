class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, res = INT_MAX;
        while (l <= h) {
            int m = (l + h) / 2;
            res = min(res, nums[m]);
            if (nums[l] < nums[h]) {
                res = min(res, nums[l]);
                return res;
            }
            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return res;
    }
};
