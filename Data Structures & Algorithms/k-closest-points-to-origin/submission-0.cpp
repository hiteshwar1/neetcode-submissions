class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < k; i++) {
            q.push({points[i][0] * points[i][0] + points[i][1] * points[i][1],
                    {points[i][0], points[i][1]}});
        }

        for (int i = k; i < points.size(); i++) {
            if (q.top().first > points[i][0] * points[i][0] + points[i][1] * points[i][1]) {
                q.pop();
                q.push({points[i][0] * points[i][0] + points[i][1] * points[i][1],
                        {points[i][0], points[i][1]}});
            }
        }
        while (!q.empty()) {
            res.push_back({q.top().second.first, q.top().second.second});
            q.pop();
        }
        return res;
    }
};
