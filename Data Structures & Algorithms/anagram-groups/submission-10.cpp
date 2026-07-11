class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> freq(26, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                freq[strs[i][j] - 'a']++;
            }
            string code = "";
            for (int k = 0; k < 26; k++) {
                code += to_string(freq[k]) + ",";
            }
            m[code].push_back(strs[i]);
        }
        for (auto i = m.begin(); i != m.end(); i++) {
            res.push_back(i->second);
        }
        return res;
    }
};
