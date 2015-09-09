ass Solution {
public:
    void swap(int &a,int &b){
       int tmp = b;
        b = a;
        a = tmp;
    }
    void rotate(vector<vector<int> > &matrix) {
        int len = matrix.size();
        int i,j;
        for(i=0;i<len;i++){
            for(j=0;j<len-i;j++){
                swap(matrix[i][j],matrix[len-1-j][len-1-i]);
            }
        }
        for(i=0;i<len/2;i++){
            for(j=0;j<len;j++){
                swap(matrix[i][j],matrix[len-i-1][j]);
            }
        }
    }
};
