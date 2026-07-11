class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> m;
        for (auto i : nums) m[i]++;
        for (int i = 0; i < nums.size(); i++) {
            int currlen = 1, currnum = nums[i];
            while (m.find(currnum - 1) != m.end()) {
                currlen++;
                currnum--;
            }
            res = max(res, currlen);
        }
        return res;
    }
};
