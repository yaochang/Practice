#include<stdio.h>
#include<stdlib.h>
   
int divide(int dividend, int divisor) {
 	//use this variable to represent the sign of the result
	int sign = 1;
	unsigned int dd;
	unsigned int ds;
	unsigned int reduce[32];
	unsigned int res=0;
	memset(reduce,0,sizeof(reduce));
	if(dividend<0){ 
		sign = sign * (-1);
		dd = -dividend;
	}else{
		dd = dividend;
	}
	if(divisor<0){
		sign = sign * (-1);
		ds = -divisor;
	}else{
		ds = divisor;
	}
	if(dd==0) return 0;
	int i=0;
	unsigned int value = ds;
	while(value>0 && value <= dd){
		reduce[i] = value;
		value = value << 1;
		i++;
	}
	i--;
	while(dd!=0 && i>=0){
		if(reduce[i]<=dd){
			dd = dd - reduce[i];
			printf("i=%d-->res=%d\n",i,1<<i);
			res = res + (1<<i);
			printf("current result:%d\n",res);
		}
		i--;
	}
	res = res * sign;
	return res;
}

int main(int argc, char** argv){
	int divident = atoi(argv[1]);
	int divisor = atoi(argv[2]);
	int res = divide(divident,divisor);
	printf("result:%d\n",res);
	return 0;
}
