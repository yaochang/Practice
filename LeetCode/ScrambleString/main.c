class Solution {
public:
    bool isScramble(string s1, string s2) {
	if(s1.length()!=s2.length()) return false;  	
	int A[26];
	memset(A,0,sizeof(A));
	bool result = false;
	int len = s1.length();
	int i;
	for(i=0;i<len;i++){
		A[s1[i]-'a']++;
	}
	for(i=0;i<len;i++){
		A[s2[i]-'a']--;
	}
	for(i=0;i<26;i++){
		if(A[i]!=0) return false; //if the letters are different return false
	}
	if(len==1) return true;
	//by partition, there are four strings, we should compared (s11,s21)and(s12,s22) || (s11,s22)and(s21,s12)
	//each of the two combination can be satisfied, accepted otherwise rejected.
	for(i=1;i<len;i++){  
		result = isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,len-i),s2.substr(i,len-i));
		if(result) return true;
	}
	for(i=1;i<len;i++){
		result = (isScramble(s1.substr(0,i),s2.substr(len-i,i)) && isScramble(s1.substr(i,len-i),s2.substr(0,len-i))); 	
		if(result) return true;	
	}
	return false;      
    }
};
