class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1, maxarea = 0;
        while (i < j) {
            maxarea = max(maxarea, (j - i) * min(heights[i], heights[j]));
            if (heights[i] < heights[j]) i++;
            else j--;
        }
        return maxarea;
    }
};
