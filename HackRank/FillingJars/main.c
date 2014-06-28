#include <stdio.h>
#include <stdlib.h>

int main(){
	long long int N,M;
	long long int start,end,number;
	long long int num = 0.0;
	scanf("%lld%lld",&N,&M);
	while(M>0){
		M--;
		scanf("%lld%lld%lld",&start,&end,&number);
	 	num = num + (end - start +1)*number;	
	}
	printf("%lld\n", num/N);
	return 0;
}
