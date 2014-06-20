ass Solution {
public:
    int climbStairs(int n) {
        int a[n+1];
        memset(a,0,sizeof(a));
        a[0] = 1;
        a[1] = 1;
        a[2] = 2;
        if(n<=2) return a[n];
        for(int i=3;i<=n;i++){
            a[i] = a[i-1] + a[i-2];
        }
        return a[n];
    }
};
