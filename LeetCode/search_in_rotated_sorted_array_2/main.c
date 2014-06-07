ass Solution {
public:
    bool search(int A[], int n, int target) {
        int l,r,m;
        l=0;
        r=n-1;
        while(l<=r){
            while(l<n-1){
                if(A[l]==A[l+1]) l = l+1;
                else break;
            }
            while(r>0){
                if(A[r]==A[r-1]) r = r-1;
                else break;
            }
            m = (l+r)/2;
            if(A[m]==target) return true;
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
        return false;
    }
};
