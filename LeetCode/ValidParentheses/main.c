class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        int i;
        char tmp;
        if(len%2==1) return false;
        if(len==0) return true;
        for(i=0;i<len;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                tmp = st.top();
                st.pop();
                if(s[i]==')' && tmp=='(') continue;
                if(s[i]==']' && tmp=='[') continue;
                if(s[i]=='}' && tmp=='{') continue;
                return false;
            }
        }
        if(!st.empty()) return false;
        else return true;
    }
};
