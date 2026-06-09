class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto i : nums) m[i]++;
        int maxlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            int currnum = nums[i];
            int currlen = 1;
            while (m.find(currnum - 1) != m.end()) {
                currnum--;
                currlen++;
            }
            maxlen = max(maxlen, currlen);
        }
        return maxlen;
    }
};
