class Solution {
   public:
    bool dfs(vector<vector<char>> board, string word, int r, int c, int i,
             vector<vector<int>>& vis) {
        if (i >= word.size()) return true;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i] ||
            vis[r][c])
            return false;
        vis[r][c] = 1;
        if (dfs(board, word, r + 1, c, i + 1, vis) || dfs(board, word, r - 1, c, i + 1, vis) ||
            dfs(board, word, r, c + 1, i + 1, vis) || dfs(board, word, r, c - 1, i + 1, vis))
            return true;
        vis[r][c] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0, vis)) return true;
                }
            }
        }
        return false;
    }
};
