class Solution {
   public:
    bool isValid(vector<vector<char>>& board, int i, int j) {
        char curr = board[i][j];
        int rowCnt = 0;
        for (int x = 0; x < 9; x++) {
            if (board[i][x] == curr) rowCnt++;
            if (rowCnt > 1) return false;
        }
        int colCnt = 0;
        for (int x = 0; x < 9; x++) {
            if (board[x][j] == curr) colCnt++;
            if (colCnt > 1) return false;
        }
        int gridCnt = 0, startRow = i - i % 3, startCol = j - j % 3;
        for (int x = startRow; x < startRow + 3; x++) {
            for (int y = startCol; y < startCol + 3; y++) {
                if (board[x][y] == curr) gridCnt++;
                if (gridCnt > 1) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!isValid(board, i, j)) return false;
                }
            }
        }
        return true;
    }
};
