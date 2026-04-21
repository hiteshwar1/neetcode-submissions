class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1, res = 0;
        while(i<j){
            res = max(res, min(heights[i], heights[j]) * (j - i));
            if(heights[i]<=heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return res;
    }
};
