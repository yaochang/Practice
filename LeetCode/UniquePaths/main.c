class Solution {
public:
    int uniquePaths(int m, int n) {
        int num[m][n];
        memset(num,0,sizeof(num));
        int i,j;
        for(i=0;i<m;i++){
            num[i][n-1] = 1;
        }
        for(j=0;j<n;j++){
            num[m-1][j] = 1;
        }
        for(j=n-2;j>=0;j--){
            for(i=m-2;i>=0;i--){
                num[i][j] = num[i+1][j] + num[i][j+1];
            }
        }
        return num[0][0];
    }
};
