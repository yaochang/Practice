#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<stack>
#include<queue>
using namespace std;

void reverseString(string &s){
	int len = s.length();
	queue<char> qu;
	stack<string> st;
	string str="";
	for(int i=0;i<len;i++){
		if(s[i]==' '){
			str="";
			while(!qu.empty()){
				str.push_back(qu.front());
				qu.pop();
			}
			if(str.length()>0){
				st.push(str);
			}
		}else{
			qu.push(s[i]);
		}
	}
	//printf("queue size:%d\n",(int)qu.size());
	if(!qu.empty()){
		str="";
		while(!qu.empty()){
			str.push_back(qu.front());
			qu.pop();	
		}
		st.push(str);
	}
	s="";
	while(!st.empty()){
		s.append(st.top());
		st.pop();
		if(!st.empty()) s.append(" ");	
	}	
}

int main(){
	string s = "Hello World!";
	reverseString(s);
	printf("%s\n",s.c_str());
	return 0;
}
