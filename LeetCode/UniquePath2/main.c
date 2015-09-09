class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size()-1;
        int n = obstacleGrid[0].size()-1;
        int num[100][100];
        memset(num,0,sizeof(num));
        int i,j;
        for(i=m;i>=0;i--){
            if(obstacleGrid[i][n]==0) num[i][n] = 1;
            else break;
        }
        for(j=n;j>=0;j--){
            if(obstacleGrid[m][j]==0) num[m][j] = 1;
            else break;
        }
        for(j=n-1;j>=0;j--){
            for(i=m-1;i>=0;i--){
                if(obstacleGrid[i][j]==1) num[i][j] = 0;
                else num[i][j] = num[i+1][j] + num[i][j+1];
            }
        }
        return num[0][0];
    }
};
