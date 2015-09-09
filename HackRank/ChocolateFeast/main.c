#include<stdio.h>
#include<stdlib.h>

int main(){
	int T,N,C,M;
	int total, cur,left,wapper;
	scanf("%d",&T);
	while(T>0){
		T--;
		scanf("%d%d%d",&N,&C,&M);
		total = 0;
		cur = 0;
		wapper = 0;
		left = N;
		total = left/C;
		left = left%C;
		wapper = total;
		while(wapper>=M){
			total = total + wapper/M;
			cur = wapper/M;
			wapper = wapper%M + cur;
		}		
		printf("%d\n",total);
	}
	return 0;
}
