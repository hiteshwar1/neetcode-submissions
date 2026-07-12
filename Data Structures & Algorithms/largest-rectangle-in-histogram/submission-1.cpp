class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> st;
        for (int i = 0; i < heights.size(); i++) {
            int startidx = i;
            while (!st.empty() && st.top().second > heights[i]) {
                int area = st.top().second * (i - st.top().first);
                res = max(res, area);
                startidx = st.top().first;
                st.pop();
            }
            st.push({startidx, heights[i]});
        }
        while (!st.empty()) {
            int area = st.top().second * (heights.size() - st.top().first);
            res = max(res, area);
            st.pop();
        }
        return res;
    }
};
