
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int len = num.size();
        bool visited[len];
        int i,j;
        unordered_map<int,int> hashmap;
        unordered_map<int,int> v;
        for(i=0;i<len;i++){
        	hashmap[num[i]] = i; /* record the postition*/
        	v[num[i]] = 0;
        	visited[i] = false;
	    }
        int max = 0;
        int tmp;
        int index;
        for(i=0;i<len;i++){
        	if(visited[i]==true || v[num[i]]==1){
        		continue;
        	}
        	visited[i] = true;
        	v[num[i]] = 1;
        	tmp = 1;
        	index = num[i] - 1;
        	while(hashmap.find(index)!= hashmap.end()){
        		tmp++;
        		v[index] = 1;
        		visited[hashmap[index]]=true;
        		index--;
        	}
        	index = num[i] + 1;
        	while(hashmap.find(index) != hashmap.end()){
        		tmp++;
        		v[index] = 1;
        		visited[hashmap[index]]=true;
        		index++;
        	}
        	if(tmp > max){
        		max = tmp;
        	}
        }
        return max;
    }
};