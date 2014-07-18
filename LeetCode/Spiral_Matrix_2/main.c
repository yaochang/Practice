#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;
 void fill(vector<vector<int> >&result, int begin, int end,int cur){
	if(begin > end) return;
	int i,j;
	for(j=begin;j<=end;j++){
		result[begin][j] = cur;
		cur++;
	}
	for(i=begin+1;i<=end;i++){
		result[i][end] = cur;
		cur++;
	}
	for(j=end-1;j>=begin;j--){
		result[end][j] = cur;
		cur++;
	}
	for(i=end-1;i>begin;i--){
		result[i][begin] = cur;
		cur++;	
	}
	fill(result,begin+1,end-1,cur);
 }
 
 vector<vector<int> > generateMatrix(int n) {
  	vector<vector<int> > result(n,vector<int>(n));
	if(n<=0) return result;
	int begin=0;
	int end=n-1;
	fill(result,begin,end,1);
	return result;      
 }

 int main(){
	vector<vector<int> > res = generateMatrix(3);
	int size = res.size();
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	return 0;
 }

