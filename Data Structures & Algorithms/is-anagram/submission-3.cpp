class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char, int> x;
        unordered_map<char, int> y;
        for(auto i: s) x[i]++;
        for(auto i: t) y[i]++;
        for(int i=0;i<s.size();i++){
            if(x[s[i]]!=y[s[i]]) return false;
        }
        return true;
    }
};
