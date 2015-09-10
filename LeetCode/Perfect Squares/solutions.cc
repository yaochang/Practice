class Solution {
    public:
        int a[100000];
        int search(int n){
            if(n==1) return a[1];
            if(n==0) return a[0];
            int ret = n;
            int tmp;
            for(int i=1;i<=sqrt(n);i++){
                tmp = n - i*i;
                if(a[tmp] == 0) a[tmp] = search(tmp);
                if(a[tmp] + 1 < ret) ret = a[tmp] + 1;
            }
            return ret;
        }

        int numSquares(int n){
            memset(a, 0, sizeof(int)*(100000));
            int ret = search(n);
            return ret;
        }
}
