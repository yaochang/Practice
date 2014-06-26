class Solution {
public:
    int min(int a,int b,int c){
        int tmp;
        if(a > b) tmp = b;
        else tmp = a;
        
        if(tmp>c) return c;
        else return tmp;
    }
    int minDistance(string word1, string word2) {
       int len1,len2;
       len1 = word1.length();
       len2 = word2.length();
       int d[len1+1][len2+1];
       memset(d,0,sizeof(d));
       int i,j;
       for(i=0;i<=len1;i++){
           d[i][0] = i;
       }
       for(j=0;j<=len2;j++){
           d[0][j] = j;
       }
       for(i=1;i<=len1;i++){
            for(j=1;j<=len2;j++){
               if(word2[j-1] == word1[i-1]){
                   d[i][j] = d[i-1][j-1];
               }else{
                   d[i][j] = min(d[i-1][j-1],d[i-1][j],d[i][j-1]) + 1;
               }
           }
       }
       return d[len1][len2];
    }
};
