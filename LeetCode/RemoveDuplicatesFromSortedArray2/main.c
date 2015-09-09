ass Solution {
public:
    int removeDuplicates(int A[], int n) {
        int curIndex=1,index=0;
        int tag=0;
        if(n==0) return 0;
        int dup=A[0];
        tag = 1;
        for(index=1;index<n;index++){
            if(A[index]==dup){
                if(tag==1){
                    A[curIndex++] = A[index];
                    tag = 2;
                    continue;
                }else if(tag==2){
                    continue;
                }
            }else{
                A[curIndex++] = A[index];
                tag = 1;
                dup = A[index];
            }
        }
        return curIndex;
    }
};
