class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            // frequency array
            vector<int> freq(26, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                freq[strs[i][j]-'a']++;
            }
            string key = "";
            for(int k=0;k<26;k++){
                key+=to_string(freq[k]) + ",";
            }
            cout<<key<<",";
            m[key].push_back(strs[i]);
        }
        for (auto i : m) {
            res.push_back(i.second);
        }
        return res;
    }
};
