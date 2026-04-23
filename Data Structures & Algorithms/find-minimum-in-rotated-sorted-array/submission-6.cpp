class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, res = INT_MAX;
        if (nums[l] < nums[h]) return nums[0];
        while (l <= h) {
            int m = (l + h) / 2;
            //if landed in sorted array
            if(nums[l]<=nums[h]){
                res = min(res, nums[l]);
                break;
            }
            res = min(res, nums[m]);
            if (nums[l] <= nums[m]) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return res;
    }
};
