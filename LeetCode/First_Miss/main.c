int firstMissingPositive(int A[], int n) {
	int i,cur;
	for(i=0;i<n;i++){
		while(A[i]!=i+1){
			//if the value is not positive or larger than n
			if(A[i]<=0 || A[i]>n) break;
			//avoid dead loop
			if(A[i] = A[A[i]-1]) break;
			cur = A[i];
			A[i] = A[cur-1];
			A[cur-1] = cur;
		}
	}
	for(i=0;i<n;i++){
		if(A[i]!=i+1) return i+1;
	}
	//if everything is right. the answer should be n+1
	return n+1;	
}
