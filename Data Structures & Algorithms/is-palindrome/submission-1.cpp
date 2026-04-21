class Solution {
public:
    bool isAlphaNum(char c){
        return (c>='a' && c <='z') || (c>='A' && c <='Z') || (c>='0' && c <='9');
    }
    bool isPalindrome(string s) {
        string str = s;
        int l = 0, r = s.size()-1;
        while(l<r){
            while(l<r && !isAlphaNum(s[l])) l++;
            while(l<r && !isAlphaNum(s[r])) r--;
            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
