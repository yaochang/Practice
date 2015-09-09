void clearStack(stack<int>&st,int&candy,int&cur){
	if(st.empty()) return;	
	int add = 0;
	int tmp;
	int pre = INT_MIN;
	int repeat = 1;
	int number = 0;
	bool tag = false;
	while(!st.empty()){
		tmp = st.top();
		st.pop();
		if(tmp!=pre){
			if(repeat>=2){
				tag = true;
				candy = candy - (add-1)*(repeat-1);
				add = 1;			
			}
			number++;
			add++;
			candy = candy + add;
			repeat = 1;
		}else{
			repeat++;
			candy = candy + add;	
		}
		pre = tmp;
	}
	if(number > 1) tag = true;
	if(repeat>=2){
		candy = candy - (add-1)*(repeat-2) - add;
		add = 1;
		if(cur > add) candy = candy + cur;
		else candy = candy + add;
	}else{
		if(cur > add) candy = candy + (cur-add);
	}
	
	if(tag == true||repeat>=2) cur = 2;
	else cur++;
}
int candy(vector<int> &ratings) {
	int size = ratings.size();
	if(size==0) return 0;
	stack<int> st;
	int preRating=INT_MAX;
	int candy = 0;
	int cur = 1;
	for(int i=0;i<size;i++){
		if(ratings[i]<=preRating){
			st.push(ratings[i]);
			preRating = ratings[i];
		}else{
			clearStack(st,candy,cur);
			preRating = ratings[i];
			st.push(ratings[i]);
		}
	}
	clearStack(st,candy,cur);
	return candy;        
}
