class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }
        int maxlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            int len = 1;
            int curr = nums[i];
            while (m.find(curr - 1) != m.end()) {
                len++;
                curr--;
            }
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};
