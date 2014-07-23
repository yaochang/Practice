 string minWindow(string S, string T) {
 	int app[256];
	int exp[256];
	memset(app,0,sizeof(app));
	memset(exp,0,sizeof(exp));
	int TLen,SLen;
	int appeared = 0;
	TLen = T.size();
	SLen = S.size();
	for(int i=0;i<TLen;i++){
		exp[T[i]]++;
	}
	int win_start = 0;
	int win_end = 0;
	int res_start = 0;
	int res_end = 0;
	int min = INT_MAX;
	for(int i=0;i<SLen;i++){
		win_end = i;
		if(exp[S[i]]>0){ //if the char is in T
			app[S[i]]++;
			if(app[S[i]] <= exp[S[i]]){
				appeared++;
			}
			if(appeared == TLen){//if all char appeared, adjust start
				while(app[S[win_start]]>exp[S[win_start]] || exp[S[win_start]]==0){
					app[S[win_start]]--;
					win_start++;
				}
				if( min > win_end - win_start + 1){
					min = win_end - win_start + 1;
					res_start = win_start;
					res_end = win_end;
				}
			}
			
		}
	}
	if(min == INT_MAX) return "";
	else return S.substr(res_start,min);
 }
