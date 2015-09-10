class Solution {
    public:
        bool isUgly(int num){
            if(num == 1 || num == 2 || num == 3 || num == 5) return true;
            if(num == 0) return false;
            bool ret = false;
            if(num%2 == 0) {
                if(isUgly(num/2)) return true;
            }
            if(num%3 == 0) {
                if(isUgly(num/3)) return true;
            }
            if(num%5 == 0) {
                if(isUgly(num/5)) return true;
            }
            return false;
        }
}
