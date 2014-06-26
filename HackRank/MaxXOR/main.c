#include<stdio.h>
#include<stdlib.h>

int main(){
	unsigned int L,R,max=0;
	unsigned int a,b;
	unsigned int tmp;
    	scanf("%d%d",&L,&R);
	for(a=L;a<=R;a++){
		for(b=a+1;b<=R;b++){
		//	printf("%d\n",a^b);
			tmp = a^b;
			if(max < tmp) max = tmp;
		}
	}
	printf("%d\n",max);
    return 0;
}
