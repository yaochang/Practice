ass Solution {
public:
    int reverse(int x) {
        int neg = 1;
        if(x<0){
            neg = -1;
            x = x*(-1);
        }
        int res = 0,add = 0;
        while(x>=10){
            add = x%10;
            x = x/10;
            res = res*10 + add;
        }
        res = res * 10 + x;
        return neg*res;
    }
};
