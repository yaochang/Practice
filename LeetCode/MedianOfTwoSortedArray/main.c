class Solution {
public:
    int min(int a,int b){
   	if(a>b) return b;
	else return a;
    }
    //get the kth number in two sorted arrays
    //by divide each array into two section, we can drop one section at each iteration
    int getMedian(int a[], int m, int b[], int n, int k){
	if(m<=0) return b[k-1];
	if(n<=0) return a[k-1];
	if(k<=1) return min(a[0],b[0]);
	// if not satisify the termination demands
	if(b[n/2] > a[m/2]){
		if(m/2+n/2+1 >= k){
			return getMedian(a,m,b,n/2,k);
		}else{
			return getMedian(a+m/2+1,m-m/2-1,b,n,k-m/2-1);
		}
	}else{
		if(m/2+n/2+1 >=k){
			return getMedian(a,m/2,b,n,k);
		}else{
			return getMedian(a,m,b+n/2+1,n-n/2-1,k-n/2-1);
		}
	}
    }

    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2==0){ //if m+n is even, we should get two numbers
		return (getMedian(A,m,B,n,(m+n)/2)+getMedian(A,m,B,n,(m+n)/2+1))/2.0;
	}else{ // if m+n is odd, we just get the median one
		return getMedian(A,m,B,n,(m+n)/2+1) * 1.0;
	}
    }
};
