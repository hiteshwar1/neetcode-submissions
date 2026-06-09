class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";
        for (int i = 0; i < strs.size(); i++) {
            res += to_string(strs[i].size()) + "#" + strs[i];
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, j = 0;
        while (j < s.size()) {
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i + 1));
            string str = s.substr(j + 1, len);
            res.push_back(str);
            j += len + 1;
            i = j;
        }
        return res;
    }
};
