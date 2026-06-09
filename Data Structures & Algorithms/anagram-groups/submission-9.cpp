class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> freq(26, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                freq[strs[i][j] - 'a']++;
            }
            string code = "";
            for (auto k : freq) {
                code += to_string(k) + ",";
            }
            m[code].push_back(strs[i]);
        }
        for (auto i : m) {
            res.push_back(i.second);
        }
        return res;
    }
};
