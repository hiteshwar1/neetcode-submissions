class Solution {
   public:
    bool helper(vector<int>& piles, int m, int h) {
        int time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += ceil((double)piles[i] / m);
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0;
        for (auto i : piles) high = max(high, i);
        int res = high;
        while (low <= high) {
            int m = (low + high) / 2;
            if (helper(piles, m, h)) {
                res = m;
                high = m - 1;
            } else {
                low = m + 1;
            }
        }
        return res;
    }
};
