class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        int startRow = 0, endRow = n - 1, startCol = 0, endCol = m - 1;
        int totalEl = n * m;
        while (totalEl) {
            for (int i = startCol; i <= endCol && totalEl > 0; i++) {
                res.push_back(matrix[startRow][i]);
                totalEl--;
            }
            startRow++;
            for (int i = startRow; i <= endRow && totalEl > 0; i++) {
                res.push_back(matrix[i][endCol]);
                totalEl--;
            }
            endCol--;
            for (int i = endCol; i >= startCol && totalEl > 0; i--) {
                res.push_back(matrix[endRow][i]);
                totalEl--;
            }
            endRow--;
            for (int i = endRow; i >= startRow && totalEl > 0; i--) {
                res.push_back(matrix[i][startCol]);
                totalEl--;
            }
            startCol++;
        }
        return res;
    }
};
