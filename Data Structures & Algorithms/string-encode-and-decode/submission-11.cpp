class Solution {
   public:
    string encode(vector<string>& strs) {
        string str = "";
        for (int i = 0; i < strs.size(); i++) {
            str.append(to_string(strs[i].size()) + "#" + strs[i]);
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, j = 0;
        while (j < s.size()) {
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i,j-i));
            res.push_back(s.substr(j+1, len));
            j = j+len+1;
            i = j;
        }
        return res;
    }
};
