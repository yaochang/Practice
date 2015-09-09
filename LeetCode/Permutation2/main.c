class Solution {
public:
    void search(vector<vector<int> >&res, vector<int>&tmp,unordered_map<int,int>&map,int cur,vector<int>&num){
	int len = num.size();
	if(cur==len){
		res.push_back(tmp);
		return;
	}
	for(auto it=map.begin();it!=map.end();++it){
		if(it->second == 0) continue;	
		tmp.push_back(it->first);
		map[it->first]--;
		search(res,tmp,map,cur+1,num);
		map[it->first]++;
		tmp.pop_back();
	}
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
  	unordered_map<int,int> map;
	int len = num.size();
	vector<vector<int> > res;
	if(len==0) return res;
	for(int i=0;i<len;i++){
		if(map.find(num[i])==map.end()){
			map[num[i]] = 1;
		}else{
			map[num[i]]++;
		}
	}
	vector<int> tmp;
	search(res,tmp,map,0,num);
	return res;
    }
};
