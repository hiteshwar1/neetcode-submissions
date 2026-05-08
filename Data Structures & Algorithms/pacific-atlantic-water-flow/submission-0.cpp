class Solution {
   public:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& vis, vector<vector<int>>& heights) {
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto x = q.front().first;
            auto y = q.front().second;
            vis[x][y] = 1;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < heights.size() && ny < heights[0].size() &&
                    !vis[nx][ny] && heights[nx][ny] >= heights[x][y]) {
                    q.push({nx, ny});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> pvis(n, vector<int>(m, 0));
        vector<vector<int>> avis(n, vector<int>(m, 0));
        queue<pair<int, int>> pq;
        queue<pair<int, int>> aq;

        for (int i = 0; i < n; i++) {
            pq.push({i, 0});
            aq.push({i, m - 1});
        }

        for (int i = 0; i < m; i++) {
            pq.push({0, i});
            aq.push({n - 1, i});
        }

        bfs(pq, pvis, heights);
        bfs(aq, avis, heights);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pvis[i][j] && avis[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
