class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(int i=0;i<strs.size();i++){
            res.append(strs[i]+".");
        }
        cout<<res;
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='.'){
                j++;
            }
            res.push_back(s.substr(i,j-i));
            i=j+1;
        }
        return res;
    }
};
