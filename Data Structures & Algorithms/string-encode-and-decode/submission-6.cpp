class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i = 0;i < strs.size();i++){
            res.append(to_string(strs[i].size()) + "." + strs[i]);
        } 
        return res;
    }

    vector<string> decode(string s) {
        vector<string> result;
        
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '.') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }
        
        return result;
    }
};
