class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket sort
        unordered_map<int, int> m;
        for (auto i : nums) m[i]++;
        vector<vector<int>> freqBucket(nums.size() + 1);
        for (auto i : m) freqBucket[i.second].push_back(i.first);
        vector<int> res;
        for (int i = freqBucket.size() - 1; i >= 0; i--) {
            for (int j : freqBucket[i]) {
                res.push_back(j);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
