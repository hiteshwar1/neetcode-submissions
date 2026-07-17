class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int l = 0, r = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[i] > nums[q.back()]) q.pop_back();
            q.push_back(i);
            if (i + 1 >= k) {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};
