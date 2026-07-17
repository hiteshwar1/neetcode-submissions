class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mt;
        unordered_map<char, int> ms;
        for (auto i : t) mt[i]++;

        int have = 0, need = mt.size();
        int i = 0, j = 0, minlen = INT_MAX;
        string res = "";
        while (j < s.size()) {
            ms[s[j]]++;
            if (mt.find(s[j]) != mt.end() && mt[s[j]] == ms[s[j]]) have++;
            while (have == need) {
                if (minlen > j - i + 1) {
                    minlen = j - i + 1;
                    res = s.substr(i, minlen);
                }
                ms[s[i]]--;
                if (mt.find(s[i]) != mt.end() && mt[s[i]] > ms[s[i]]) have--;
                i++;
            }
            j++;
        }
        return res;
    }
};
