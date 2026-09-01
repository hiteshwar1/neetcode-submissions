class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int i = 0, j = 0;
        unordered_set<char> st;
        while (j < s.size()) {
            while (st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};
