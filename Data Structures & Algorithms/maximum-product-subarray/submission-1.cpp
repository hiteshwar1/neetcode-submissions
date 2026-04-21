class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, maxi = 1, mini = 1;
        for(int i=0; i<nums.size(); i++){
            int tmp = maxi;
            maxi = max(nums[i], max(maxi*nums[i], mini*nums[i]));
            mini = min(nums[i], min(mini*nums[i], tmp*nums[i]));
            res = max(res,maxi);
        }
        return res;
    }
};
