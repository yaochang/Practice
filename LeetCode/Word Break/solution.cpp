class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        bool tmpRes[len+1];
        int i;
        int tmpLen=0;
        tmpRes[0]=true;
        unordered_set<string>::iterator p;
        string tmpStr="";
        //s[1:n-1] can be break?
        for(i=1;i<=len;i++){ 
            tmpRes[i] = false;
            for(p=dict.begin();p!=dict.end();p++){
                tmpStr=*p;
                tmpLen = tmpStr.length();
                if(tmpLen > i) continue;
                else{
                    if(s.compare(i-tmpLen,tmpLen,tmpStr) == 0){
                        tmpRes[i] = tmpRes[i-tmpLen];
                        if(tmpRes[i] == true) break;
                    }
                }
            }
        }
        return tmpRes[len];
    }
};