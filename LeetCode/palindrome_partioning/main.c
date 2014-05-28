#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

void DFS(string& s, int begin, vector<string>& output, vector<vector<string> >&result,bool* flag){
        int len = s.size();
        int i;
        int bindex=begin,eindex;
        if(begin >= len){
            result.push_back(output);
            return;
        }
        for(i=begin;i<len;i++){
            eindex = i;
            if(flag[bindex*len+eindex]==true){
                output.push_back(s.substr(bindex,eindex-bindex+1));
                DFS(s,eindex+1,output,result,flag);
                output.pop_back();
            }
        }
        return;
    }
vector<vector<string> > partition(string s) {
         int len = s.size();
         int i,j;
         bool flag[len*len];
         vector<string> output;
         vector<vector<string> > result;
         for(i=0;i<len;i++){
             flag[i*len+i] = true;
         }
         int bindex,eindex;
         for(j=1;j<len;j++){
             for(i=0;i<len;i++){
                 bindex = i;
                 eindex = i + j;
                 if(eindex>=len) break;
                 if(bindex+1 > eindex-1){
                     if(s[eindex]==s[bindex]){
                          flag[bindex*len+eindex] = true;
                     }
                     else flag[bindex*len+eindex] = false;
                 }else{
                     if(flag[(bindex+1)*len+eindex-1]==true && s[bindex]==s[eindex]){
                         flag[bindex*len+eindex] = true;
                     }else{
                         flag[bindex*len+eindex] = false;
                     }
                 }
             }
         }
         DFS(s,0,output,result,flag);
         return result;
    }
int main(){
    string s = "aaabb";
    vector<vector<string> > result;
    result = partition(s);
    return 0;
}