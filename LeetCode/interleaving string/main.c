class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if((len1+len2)!=len3) return false;
        int tag[(len1+1)*(len2+1)];
        memset(tag,0,sizeof(tag));
        int i,j;
        i = len1;
        j = len2;
        tag[i*len2+j] = judge(s1,s2,s3,len2,tag);
        if(tag[i*len2+j]==1) return true;
        else return false;
    }
    int judge(string s1,string s2,string s3,int len,int*tag){
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        int i=len1;
        int j=len2;
        if((s1==s3 && len2==0)||(s2==s3 && len1==0)){
            tag[i*len+j] = 1;
            return 1;
        }
        if(s1[len1-1]==s3[len3-1]){
            if(tag[(len1-1)*len+len2]==0){
               tag[(len1-1)*len+len2] = judge(s1.substr(0,len1-1),s2,s3.substr(0,len3-1),len,tag);
            }
            if(tag[(len1-1)*len+len2] == 1) return 1;
        }
        if(s2[len2-1]==s3[len3-1]){
            if(tag[len1*len+len2-1]==0){
                tag[len1*len+len2-1] = judge(s1,s2.substr(0,len2-1),s3.substr(0,len3-1),len,tag);
            }
            if(tag[len1*len+len2-1]==1) return 1;
        }
        return 2;
    }
};
