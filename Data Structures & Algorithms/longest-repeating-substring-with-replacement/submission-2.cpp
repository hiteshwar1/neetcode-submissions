class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> m;
        int maxfreq = 0, i = 0, j = 0, maxlen = 0;
        while (j < s.size()) {
            m[s[j]]++;
            maxfreq = max(maxfreq, m[s[j]]);
            if (j - i + 1 - maxfreq <= k) {
                maxlen = max(maxlen, j - i + 1);
            } else {
                m[s[i]]--;
                if (m[s[i]] == 0) m.erase(s[i]);
                i++;
            }
            j++;
        }
        return maxlen;
    }
};
