class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxres = 1, minres = 1, res = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            int temp = maxres;
            maxres = max(nums[i],max(maxres*nums[i],minres*nums[i]));
            minres = min(nums[i],min(minres*nums[i],temp*nums[i]));
            res = max(res,maxres);
        }
        return res;
    }
};
