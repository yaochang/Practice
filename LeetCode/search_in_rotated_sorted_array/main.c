ass Solution {
public:
    int search(int A[], int n, int target) {
        int l,r,m;
        l=0;
        r=n-1;
        while(l<=r){
            m = (l+r)/2;
            if(A[m]==target) return m;
            if(A[m] >= A[l]){
                if(A[l] <= target && target <= A[m]){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }else{
                if(target<=A[r] && A[m]<=target){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
        }
        return -1;
    }
};
