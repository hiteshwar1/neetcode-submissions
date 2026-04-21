class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // frequency array will be same for anagram and we make a string out of that
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            vector<int> freqArr(26,0);
            for(int j=0;j<strs[i].size();j++){
                freqArr[strs[i][j] - 'a']++;
            }
            string key = "";
            for(int k=0;k<26;k++){
                key.append("," + to_string(freqArr[k]));
            }
            m[key].push_back(strs[i]);
        }
        for(auto i = m.begin();i!=m.end();i++){
            res.push_back(i->second);
        }
        return res;
    }
};
