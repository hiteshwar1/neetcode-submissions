class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i: nums){
            m[i]++;
        }
        int res = 0;
        for(int i=0;i<nums.size();i++){
            int currNum = nums[i];
            int currLen = 1;
            while(m.find(currNum-1)!=m.end()){
                currNum--;
                currLen++;
            }
            res = max(res,currLen);
        }
        return res;
    }
};
