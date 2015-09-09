ass Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin=0,end=n-1;
        int mid;
        if(n==0) return 0;
        int index=0;
        if(target > A[n-1]) return n;
        while(begin<=end){
            mid = (begin+end)/2;
            if(A[mid] == target) return mid;
            if(A[mid] < target){
                begin = mid+1;
                index = begin;
            }
            if(A[mid] > target){
                end = mid-1;
                index = mid;
            }
        }
        return index;
    }
};
