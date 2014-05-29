class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start.size()==0 || dict.size()==0) return 0;
        unordered_set<string> backdict;
        unordered_map<string,int> level;
        queue<string> q;
       	backdict.insert(dict.begin(),dict.end());
        q.push(start);
        level[start] = 1;
        int tmpLevel;
        int i,j;
        string str;
        while(!q.empty()){
        	str = q.front();
        	q.pop();
        	tmpLevel = level[str];
        	for(i=0;i<str.size();i++){
        		for(char j='a';j<='z';j++){
        			if(str[i] == j) continue;
        			char temp = str[i];
        			str[i] = j;
        			if(str == end){
        				return tmpLevel+1;
        			}
        			if(backdict.count(str)>0){
        				q.push(str);
        				level[str] = tmpLevel+1;
        				backdict.erase(str);
        			}
        			str[i] = temp;
        		}
        	}
        }
        if(level.find(end)!=level.end()){
        	return level[end];
        }else{
        	return 0;
        }

    }
};