class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for (auto i : nums) m[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto i = m.begin(); i != m.end(); i++) {
            if (q.size() < k) {
                q.push({i->second, i->first});
            } else if (i->second > q.top().first) {
                q.pop();
                q.push({i->second, i->first});
            }
        }
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
