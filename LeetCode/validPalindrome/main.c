class Solution {
public:
	bool eligibile(char a){
		if(a>='0'&&a<='9'){
			return true;
		}
		if(a>='a'&&a<='z'){
			return true;
		}
		return false;
	}
    bool isPalindrome(string s) {
        if(s.size()==0) return true;
        int begin,end;
        int len = s.size();
        for(int i=0;i<len;i++){
            if(s[i]>='A'&&s[i]<='Z'){
                s[i] = s[i] - ('A'-'a');
            }
        }
        bool tag = false;
        begin = 0;
        end = s.size()-1;
        while(begin<end){
        	if(!eligibile(s[begin])){
        		begin++;
        		continue;
        	}
        	if(!eligibile(s[end])){
        		end--;
        		continue;
        	}
        	if(s[begin]==s[end]){
        		begin++;
        		end--;
        	}else{
        		return false;
        	}
        }
        return true;
    }
};