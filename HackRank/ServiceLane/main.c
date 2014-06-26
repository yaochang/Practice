#include<stdio.h>
#include<stdlib.h>

int main(){
	int N,T;
	int width[100000];
	scanf("%d%d",&N,&T);
	int start,end;
	for(int i=0;i<N;i++){
		scanf("%d",&(width[i]));
	}	
	int count=0;
	int min = 4;
	while(count<T){
		count++;
		min = 4;
		scanf("%d%d",&start,&end);
		for(int i=start;i<=end;i++){
			if(width[i]<min) min = width[i];
			if(min == 1) break;
		}
		printf("%d\n",min);
	}
	return 0;
}
