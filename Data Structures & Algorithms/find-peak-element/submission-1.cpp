class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int l = 0, h = nums.size() - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (m == 0) {
                if (nums[m] > nums[m + 1])
                    return 0;
                else if (nums[m] < nums[m + 1])
                    return 1;
            } else if (m == nums.size() - 1) {
                if (nums[m - 1] < nums[m])
                    return nums.size() - 1;
                else if (nums[m - 1] > nums[m])
                    return nums.size() - 2;
            }
            else if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) return m;
            else if (nums[m] > nums[m - 1] && nums[m] < nums[m + 1]) l = m + 1;
            else h = m - 1;
        }
        return -1;
    }
};