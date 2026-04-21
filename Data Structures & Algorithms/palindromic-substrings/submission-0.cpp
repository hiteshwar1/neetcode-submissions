class Solution {
public:
    int countPali(string s, int l, int r){
        int cnt = 0;
        while(l>=0&&r<s.size()&&s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int res = 0;
        for(int i=0;i<s.size();i++){
            res+=countPali(s,i,i);
            res+=countPali(s,i,i+1);
        }
        return res;
    }
};
