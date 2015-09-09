ass Solution {
public:
    int removeDuplicates(int A[], int n) {
        int num=1,i=1;
        if(n==0) return 0;
        int cur=A[0];
        while(i<n){
            if(A[i]!= cur){
                 A[num++] = A[i];
                 cur = A[i];
            }
            i++;
        }
        return num;
    }
};
