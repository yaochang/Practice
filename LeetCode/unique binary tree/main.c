class Solution {
public:
    int numTrees(int n) {
        int res[n+1];
        res[0]=1;
        res[1]=1;
        res[2]=2;
        if(n<=2) return res[n];
        int i,j;
        for(i=3;i<=n;i++){
            res[i]=0;
            for(j=1;j<=i;j++){
                res[i] = res[i] + res[j-1]*res[i-j];
            }
        }
        return res[n];
    }
};
