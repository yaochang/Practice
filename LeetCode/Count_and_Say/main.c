string countAndSay(int n) {
	string str="1";
	string newstring="";
	char last = '1';
	int cur = 1;
	int count = 0;
	while(cur<n){
		last = str[0];
		count = 0;
		for(int i=0;i<=str.size();i++){
			if(str[i]==last){
				count++;
				continue;
			}else{
				newstring.append(1,count+'0');
				newstring.append(1,last);
				last = str[i];
				count = 1;	
			}	
		}
		str = newstring;
		newstring="";
		cur++;
	}
	return str;        
}
