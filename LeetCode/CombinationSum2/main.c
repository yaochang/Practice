void search(vector<vector<int> >&res,vector<int>&tmpRes,vector<int>& num, set<int> &candidate, unordered_map<int,int>&left,int current,int target,int base){ 
	if(current==target){
		res.push_back(tmpRes);
		return;
	}
	if(current > target) return;
	int cur;
	for(auto it=candidate.begin();it!=candidate.end();++it){
		cur = *it;
		if(cur < base) continue;
		if(cur + current > target) return;
		if(left[cur]>0){
			current = current + cur;
			left[cur]--;
			tmpRes.push_back(cur);
			search(res,tmpRes,num,candidate,left,current,target,cur);
			tmpRes.pop_back();
			left[cur]++;
			current = current - cur;
		}
	}
	return;
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) {
         vector<vector<int> > res;
         vector<int> tmpRes;
         set<int> candidate;
         unordered_map<int,int> left;
         int size = num.size(); 
         if(size==0) return res;
         std::sort(num.begin(),num.end());
         for(int i=0;i<size;i++){
                 left[num[i]]++;
                 candidate.insert(num[i]);
         }
         search(res,tmpRes,num,candidate,left,0,target,0);
	 return res;
}

