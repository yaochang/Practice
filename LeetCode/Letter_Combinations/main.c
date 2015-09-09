class Solution {
public:
    void search(string digits,int curIndex,string &str,vector<string>&res,unordered_map<char,string>&mapping){
	int len = digits.size();
	//if all the digits are been translated, save the result "str" to "res".
	if(len == curIndex){
		res.push_back(str);
		return;
	}
	//iterate all possible letters
	string letter = mapping[digits[curIndex]];
	int l = letter.size();
	for(int i=0;i<l;i++){
		str = str + letter.substr(i,1);
		search(digits,curIndex+1,str,res,mapping);
		str = str.substr(0,str.size()-1);
	}	
    }
    vector<string> letterCombinations(string digits) {
  	unordered_map<char,string> mapping;
	mapping['1']="";
	mapping['2']="abc";
	mapping['3']="def";
	mapping['4']="ghi";
	mapping['5']="jkl";
	mapping['6']="mno";
	mapping['7']="pqrs";
	mapping['8']="tuv";
	mapping['9']="wxyz";
	vector<string> res;
	string str = "";
	search(digits,0,str,res,mapping);
	return res;      
    }
};
