#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int N,i,count=0,len;
	char str[100];
	int d[26];
	memset(d,0,sizeof(d));
	scanf("%d",&N);
	while(count<N){
		count++;
		scanf("%s",str);
		len = strlen(str);
		for(i=0;i<len;i++){
			if(d[str[i]-'a']==count-1) d[str[i]-'a'] = count;
		}		
	}
	int res = 0;
	for(i=0;i<26;i++){
		if(d[i]==N) res++;	
	}
	printf("%d\n",res);
	return 0;
}

