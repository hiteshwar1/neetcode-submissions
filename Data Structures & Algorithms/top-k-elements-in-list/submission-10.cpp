class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> freq;
        for (auto i : nums) {
            freq[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto i = freq.begin(); i != freq.end(); i++) {
            if (q.size() < k)
                q.push({i->second, i->first});
            else {
                if (q.top().first < i->second) {
                    q.pop();
                    q.push({i->second, i->first});
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
