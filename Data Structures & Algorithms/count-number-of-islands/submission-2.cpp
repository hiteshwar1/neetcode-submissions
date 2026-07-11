class Solution {
   public:
    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') return;
        grid[i][j] = '#';
        dfs(grid, n, m, i - 1, j);
        dfs(grid, n, m, i + 1, j);
        dfs(grid, n, m, i, j - 1);
        dfs(grid, n, m, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, n, m, i, j);
                }
            }
        }
        return res;
    }
};
