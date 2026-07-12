class Solution {
   public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int i = 0, j = 0;
        unordered_map<int, int> m;
        int maxfreq = 0;
        while (j < s.size()) {
            m[s[j]]++;
            maxfreq = max(maxfreq, m[s[j]]);
            if (j - i + 1 - maxfreq <= k) {
                res = max(res, j - i + 1);
            } else {
                m[s[i]]--;
                if (m[s[i]] == 0) m.erase(s[i]);
                i++;
            }
            j++;
        }
        return res;
    }
};
