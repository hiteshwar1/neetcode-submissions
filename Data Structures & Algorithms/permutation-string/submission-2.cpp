class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (auto i : s1) {
            freq1[i - 'a']++;
        }
        for (int i = 0; i < s1.size(); i++) {
            freq2[s2[i] - 'a']++;
        }
        int i = 0, j = s1.size();
        while (j < s2.size()) {
            if (freq1 == freq2)
                return true;
            else {
                freq2[s2[i] - 'a']--;
                i++;
                freq2[s2[j] - 'a']++;
                j++;
            }
        }
        return freq1 == freq2;
    }
};
