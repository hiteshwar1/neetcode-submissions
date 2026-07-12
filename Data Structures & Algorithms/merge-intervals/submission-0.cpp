class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (res.empty() || res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            } else if (res.back()[1] >= intervals[i][0]) {
                vector<int> arr = {res.back()[0], max(res.back()[1], intervals[i][1])};
                res.pop_back();
                res.push_back(arr);
            }
        }
        return res;
    }
};
