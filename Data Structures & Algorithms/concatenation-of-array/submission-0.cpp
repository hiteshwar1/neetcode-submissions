class Solution {
   public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(2 * n, -1);
        for (int i = 0; i < 2 * n; i++) {
            arr[i] = nums[i % n];
        }
        return arr;
    }
};