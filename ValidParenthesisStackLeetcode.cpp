class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
                st.push(s[i]);
            else {
                if(!st.empty()) {
                    char t = st.top();
                st.pop();
                if((s[i]==')' and t=='(') or (s[i]=='}' and t=='{') or (s[i]==']' and t=='[')) continue;
                else return false;
                } else {
                    return false;
                }
            }
                
        }
        if(st.empty()) return true;
        else return false;
    }
};
