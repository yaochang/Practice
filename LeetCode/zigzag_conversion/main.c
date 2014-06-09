ass Solution {
public:
    string convert(string s, int nRows) {
        if(nRows==1) return s;
        string str[nRows];
        int index=0;
        int i;
        int len = s.length();
        int dir = 1;
        for(i=0;i<nRows;i++) str[i]="";
        for(i=0;i<len;i++){
            str[index] = str[index]+s[i];
            if(dir==1){
                index = index + 1;
                if(index == nRows){
                    index = nRows-2;
                    dir = 0;
                }
            }else{
                index = index - 1;
                if(index == -1){
                    index = 1;
                    dir = 1;
                }
            }
        }
        string res = "";
        for(i=0;i<nRows;i++){
            res = res + str[i];
        }
        return res;
        
    }
};
