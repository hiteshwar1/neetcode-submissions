class Solution {
   public:
    int trap(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;
        int leftmax = height[left], rightmax = height[right];
        while (left < right) {
            if (leftmax < rightmax) {
                left++;
                leftmax = max(leftmax, height[left]);
                res += leftmax - height[left];
            } else {
                right--;
                rightmax = max(rightmax, height[right]);
                res += rightmax - height[right];
            }
        }
        return res;
    }
};
