class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        stack<int> st;
        vector<int> res;
        int len = digits.size();
        int add = 1;
        int dig;
        for(int i=len-1;i>=0;i--){
            dig = digits[i] + add;
            if(dig>=10) add = 1;
            else add = 0;
            dig = dig % 10;
            st.push(dig);
        }
        if(add == 1) st.push(1);
        while(!st.empty()){
            dig = st.top();
            res.push_back(dig);
            st.pop();
        }
        return res;
    }
};
