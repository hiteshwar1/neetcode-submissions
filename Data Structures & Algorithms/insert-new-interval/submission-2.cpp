class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int l = 0, h = intervals.size() - 1;
        int x = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (intervals[m][0] < newInterval[0]) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        intervals.insert(intervals.begin() + l, newInterval);
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
