class Solution {
public:
    int min(int a,int b){
        if(a>=b) return b;
        else return a;
    }
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int distance[m][n];
        memset(distance,0,sizeof(distance));
        distance[m-1][n-1] = grid[m-1][n-1];
        int i,j;
        for(i=m-2;i>=0;i--){
            distance[i][n-1] = grid[i][n-1] + distance[i+1][n-1];
        }
        for(j=n-2;j>=0;j--){
            distance[m-1][j] = grid[m-1][j] + distance[m-1][j+1];
        }
        for(j=n-2;j>=0;j--){
            for(i=m-2;i>=0;i--){
                distance[i][j] = grid[i][j] + min(distance[i][j+1],distance[i+1][j]);
            }
        }
        return distance[0][0];
    }
};
