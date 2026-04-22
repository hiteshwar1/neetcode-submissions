class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int i = 0, j = 0, maxLen = 0, maxFreq = 0;
        while (j < s.size()) {
            m[s[j]]++;
            maxFreq = max(maxFreq, m[s[j]]);
            if (j - i + 1 - maxFreq <= k) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                m[s[i]]--;
                if (m[s[i]] == 0) m.erase(s[i]);
                i++;
            }
            j++;
        }
        return maxLen;
    }
};
