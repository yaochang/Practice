#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<set>
#include<unordered_map>
#include<string>
#include<iostream>

using namespace std;

void initializeIndex(vector<string>&L,string S,unordered_map<string,set<int> >&index){
	int size = L.size();
	string word;
	size_t found;
	//For each word in L, we should find the index in S
	for(int i=0;i<size;i++){
		word = L[i];
		set<int> wordIndex;
		found = -1;
		while(true){
			found = S.find(word,found+1);
			if(found==std::string::npos) break;
			wordIndex.insert((int)found);	
		}
		index[word] = wordIndex;
	}
}
void initializeTag(vector<string>&L,unordered_map<string,int>&tag){
	int size = L.size();
	for(int i=0;i<size;i++){
		tag[L[i]] = 0;
	}
}
void search(int begin,int curIndex,vector<int>&res,int level,unordered_map<string,set<int> >&index,unordered_map<string,int>&tag,vector<string>&L,string S){
	int size = L.size();
	if(level==size){
		res.push_back(begin);
		return;
	}
	//some optimization: if the left string is small than the dictionary words, we can return.
	if((size-level)*L[0].size()+curIndex > S.size()) return; 
	string word;
	int wordLength;
	for(int i=0;i<size;i++){
		word = L[i];
		wordLength = word.size();
		if(tag[word]==0){//if this word is not been used
			set<int> indexSet = index[word];
			if(indexSet.find(curIndex)!=indexSet.end()){ //if the word can be concatenated
				tag[word] = 1;
				search(begin,curIndex+wordLength,res,level+1,index,tag,L,S);
				tag[word] = 0;
			}
		}
	}
}


//vector<int> findSubstring(string S, vector<string> &L) {
//      vector<int> res;
//      int size = L.size();
//      int length = S.size();
//      if(size==0 || length==0) return res;
//
//      unordered_map<string,set<int> > index;
//      initializeIndex(L,S,index);
//      unordered_map<string,int> tag;
//      initializeTag(L,tag);
//      res.clear();
//      //int wordLength = L[0].size();
//      for(int i=0;i<length-wordLength*size+1;i++){
//      	search(i,i,res,0,index,tag,L,S);
//      }
//      return res;
//}

  vector<int> findSubstring(string S, vector<string> &L){
	int len = S.size();
	int size = L.size();
	vector<int> res;
	if(len==0 || size==0) return res;
	int wordLength = L[0].size();
	unordered_map<string,int> expectCount;
	unordered_map<string,int> realCount;
	int i,j;
	for(i=0;i<size;i++){
		expectCount[L[i]]++;
	}
	for(i=0;i<len-size*wordLength+1;i++){
		realCount.clear();
		for(j=0;j<size;j++){
			string substr = S.substr(i+j*wordLength,wordLength);
			if(expectCount.find(substr)!=expectCount.end()){
				realCount[substr]++;
			}else{
				break;
			}
			if(realCount[substr] > expectCount[substr]) break;
		}
		if(j==size) res.push_back(i);
	}
	return res;
  }


int main(){
	string S="barfoothefoobarman";
	vector<string> L;
	L.push_back("foo");
	L.push_back("bar");
	vector<int> res = findSubstring(S,L);
	printf("size:%d\n",res.size());
	for(int i=0;i<res.size();i++){
		printf("index:%d\n",res[i]);
	}
	return 0;	
}
