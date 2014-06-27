#include<stdio.h>
#include<stdlib.h>

int main(){
	int N,n,a,b;
	scanf("%d",&N);
	while(N>0){
		N--;
		scanf("%d%d%d",&n,&a,&b);
		if(a==b){
			printf("%d \n",n*a);
			continue;
		}
		int tmp;
		if(a>b){
			tmp = a;
			a = b;
			b = tmp;
		}
		for(int i=n-1;i>=0;i--){
			printf("%d ",i*a+(n-1-i)*b);
		}
		printf("\n");
	}
	return 0;
}
