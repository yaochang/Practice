class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length();
        int len2 = b.length();
        int len;
        if(len1>len2){
            len = len1+1;
        }else{
            len = len2+1;
        }
        string tmp="";
        for(int i=0;i<len-len1;i++){
            tmp = "0"+tmp;
        }
        a = tmp + a;
        tmp="";
        for(int i=0;i<len-len2;i++){
            tmp = "0" + tmp;
        }
        b = tmp + b;
        int add = 0;
        int res = 0;
        string retval="";
        for(int i=0;i<len;i++){
            retval = "0" + retval;
        }
        for(int i=len-1;i>=0;i--){
            res = a[i]-'0' + b[i]-'0' + add;
            if(res >= 2) add = 1;
            else add = 0;
            res = res % 2;
            retval[i] = res + '0';
        }
        if(retval[0]=='1') return retval;
        else return retval.substr(1);
    }
};
