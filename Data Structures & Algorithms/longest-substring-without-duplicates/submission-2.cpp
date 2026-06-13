class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int maxlen = 0, i = 0, j = 0;
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
