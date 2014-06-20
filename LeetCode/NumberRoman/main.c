class Solution {
public:
    int romanToInt(string s) {
  	int len = s.length();
	unordered_map<char,int> mapping;
	mapping['I'] = 1;
	mapping['V'] = 5;
	mapping['X'] = 10;
	mapping['L'] = 50;
	mapping['C'] = 100;
	mapping['D'] = 500;
	mapping['M'] = 1000;
	int cur = mapping[s[0]];
	int total = cur;
	int temp = cur;
	for(int i=1;i<len;i++){
		if(mapping[s[i]]<=cur){
			total = total + mapping[s[i]];
			cur = mapping[s[i]];
		}else{
			total = total + mapping[s[i]] - 2*cur;
			cur = mapping[s[i]];
		}
	}
	return total;
  }
};
