class Solution {
public:
    string getNum(string str){
        string num = "";
        sort(str.begin(),str.end());
        for(int i=0;i<str.size();i++){
            num.append(to_string(str[i]-'a'));
        }
        return num;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            m[getNum(strs[i])].push_back(strs[i]);
        }
        for(auto i = m.begin(); i!=m.end(); i++){
            res.push_back(i->second);
        }
        return res;
    }
};
