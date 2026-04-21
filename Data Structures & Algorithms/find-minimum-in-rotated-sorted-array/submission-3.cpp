class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, res = INT_MAX;
        while(l<=r){
            int m = (l+r)/2;
            if(nums[l]<=nums[r]){
                res = min(res, nums[l]);
                break;
            }
            res = min(res, nums[m]);
            if(nums[r]<=nums[m]){
                l = m+1;
            }
            else{
                r = m-1;
            }
            
        }
        return res;
    }
};
