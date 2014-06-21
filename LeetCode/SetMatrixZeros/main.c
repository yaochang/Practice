class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        set<int> row,column;
        int m = matrix.size();
        int n = matrix[0].size();
        int i,j;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        set<int>::iterator it;
        int r,c;
        for(it=row.begin();it!=row.end();++it){
            r = *it;
            for(j=0;j<n;j++){
                matrix[r][j] = 0;
            }
        }
        for(it=column.begin();it!=column.end();++it){
            c = *it;
            for(i=0;i<m;i++){
                matrix[i][c] = 0;
            }
        }
        
    }
};
