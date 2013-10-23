//dynamic algorithm
class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i,j;
        int a[n];
        if(n==1) return 0;
        a[n-1] = 0;
        for(i=n-2;i>=0;i--){
            a[i]=n+1;
            if(A[i]==0) continue;
            
            if(A[i] + i >= n-1){
                a[i]=1;
            }else{
                int min=n+1;
                for(j=1;j<=A[i];j++){
                    if(a[i+j] < min) min = a[i+j];
                }
                a[i] = min+1;
            }
        }
        return a[0];
    }
};


//greedy algorithm
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lowdist=0;
        int highdist=0;
        if(n==1) return 0;
        int minstep=0;
        int posdist=0;
        int lastdist=0;
        while(lowdist<=highdist){
            minstep++;
            lastdist=highdist;
            for(int i=lowdist;i<=lastdist;i++){
                posdist = i + A[i];
                if(posdist>=n-1) return minstep;
                if(posdist>highdist) highdist = posdist;
            }
            lowdist = lastdist + 1;
        }
        return 0;
    }
};