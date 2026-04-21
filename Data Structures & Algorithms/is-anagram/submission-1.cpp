class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()) return false;

        unordered_map<char,int> sm;
        unordered_map<char,int> tm;

        for(auto i: s){
            sm[i]++;
        }
        for(auto i: t){
            tm[i]++;
        }

        for(auto i: s){
            if(sm[i]!=tm[i]) return false;
        }
        return true;
    }
};
