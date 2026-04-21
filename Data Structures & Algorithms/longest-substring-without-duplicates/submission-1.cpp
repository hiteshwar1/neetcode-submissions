class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i = 0, j = 0, res = 0;
        while(j<s.size()){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};
