class Solution {
public:
    void traverse(vector<string>&res,string &str,int n,int deep,int leftNum,int rightNum){
        if(deep == 2*n){
            res.push_back(str);
            return;
        }
        if(leftNum<n){
            str = str + "(";
            traverse(res,str,n,deep+1,leftNum+1,rightNum);
            str.resize(str.size()-1);
        }
        if(rightNum < leftNum){
            str = str + ")";
            traverse(res,str,n,deep+1,leftNum,rightNum+1);
            str.resize(str.size()-1);
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string> res;
       if(n==0) return res;
       string str;
       traverse(res,str,n,0,0,0);
       return res;
    }
};
