class Solution {
public:
    void sortColors(int A[], int n) {
        int num[3];
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++){
            num[A[i]]++;
        }
        memset(A,0,sizeof(A));
        for(int i=0;i<num[0];i++){
            A[i] = 0;
        }
        for(int i=0;i<num[1];i++){
            A[num[0]+i]=1;
        }
        for(int i=0;i<num[2];i++){
            A[num[0]+num[1]+i]=2;
        }
    }
};
