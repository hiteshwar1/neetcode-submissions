class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> x(26, 0);
        vector<int> y(26, 0);
        for (auto i : s1) x[i - 'a']++;
        for (int i = 0; i < s1.size(); i++) y[s2[i] - 'a']++;
        int i = 0, j = s1.size();
        while (j < s2.size()) {
            if (x == y) {
                return true;
            } else {
                y[s2[i] - 'a']--;
                i++;
                y[s2[j] - 'a']++;
                j++;
            }
        }
        return x == y;
    }
};
