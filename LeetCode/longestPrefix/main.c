ass Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int len = strs.size();
        string str;
        if(len==0) return "";
        int b=0,e=len-1;
        str = prefix(strs,b,e);
        return str;
    }
    int min(int a,int b){
        if( a>=b ) return b;
        else return a;
    }
    string findPrefix(string str1,string str2){
            int len1 = str1.length();
            int len2 = str2.length();
            int minlen = min(len1,len2);
            string str;
            for(int i=0;i<minlen;i++){
                if(str1[i]==str2[i]){
                    str.append(str1,i,1);
                }else{
                    break;
                }
            }
            return str;
    }
    string prefix(vector<string>&strs,int begin,int end){
        if(begin==end) return strs[begin];
        string str;
        string str1,str2;
        int len1,len2,minlen;
        if(begin+1 == end){
            str1 = strs[begin];
            str2 = strs[end];
            str = findPrefix(str1,str2);
            return str;
        }
        int mid = (begin+end)/2;
        str1 = prefix(strs,begin,mid);
        str2 = prefix(strs,mid,end);
        str = findPrefix(str1,str2);
        return str;
    }
};
