class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int begin = 0, end = m*n-1;
        int mid;
        int i,j;
        while(begin <= end){
            mid = (begin+end)/2;
            i = mid / n;
            j = mid % n;
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] < target){
                begin = mid+1;
            }
            if(matrix[i][j] > target){
                end = mid-1;
            }
        }
        return false;
    }
};
