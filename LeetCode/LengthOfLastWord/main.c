class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int start=1,end=-1,length=0;
        int len = strlen(s);
        int tag = 0;
        for(int i=len-1;i>=0;i--){
            if(s[i]==' '){
                if(tag == 0) continue;
                return length;
            }else{
                tag = 1;
                length++;
            }
        }
        if(length>0) return length;
        else return 0;
    }
};
