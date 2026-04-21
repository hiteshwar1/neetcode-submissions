class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(int i=0;i<strs.size();i++){
            str += to_string(strs[i].size()) + "#" + strs[i];
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> arr;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length = stoi(s.substr(i,j-i));
            string str = s.substr(j+1,length);
            arr.push_back(str);
            i = j+1+length;
        }
        return arr;
    }
};
