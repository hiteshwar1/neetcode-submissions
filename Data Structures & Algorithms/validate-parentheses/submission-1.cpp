class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(!st.empty()&&((st.top()=='('&&s[i]==')')||(st.top()=='{'&&s[i]=='}')||(st.top()=='['&&s[i]==']'))) st.pop();
            else if(s[i]=='('||s[i]=='{'||s[i]=='[') st.push(s[i]);
            else return false;
        }
        return st.empty();
    }
};
