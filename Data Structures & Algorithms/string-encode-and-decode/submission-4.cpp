class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(auto i:strs){
            res.append(i);
            res.append(".");
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> arr;
        int i=0,j=0;
        while(j<s.size()){
            if(s[j]!='.') j++;
            else{
                arr.push_back(s.substr(i,j-i));
                j++;
                i = j;
            }
        }
        return arr;
    }
};
