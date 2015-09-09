class Solution {
public:
    double pow(double x, int n) {
        double res = 0.0;
        int neg = 1;
        if(n<0) neg = -1;
        n = abs(n);
        if(n==0) res =  1.0;
        else if(n==1) res =  x;
        else if(n%2==0){
            res = pow(x,n/2);
            res = res * res;
        }else{
            res = pow(x,n/2);
            res = res * res * x;
        }
        if(neg == -1) res = 1.0 / res;
        return res;
    }
};
