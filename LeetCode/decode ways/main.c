ass Solution {
	public:
		    int numDecodings(string s) {
				        int len = s.length();
						        if(len==0) return 0;
								        int num[len+1];
										        memset(num,0,sizeof(num));
												        num[0]=1;
														        if(s[0]=='0') return 0;
																        num[1]=1;
																		        int cur=0;
																				        for(int i=2;i<=len;i++){
																							            cur = 0;
																										            int d2 = atoi(s.substr(i-2,2).c_str());
																													            if(d2>=10&&d2<=26) cur = cur + num[i-2];
																																            if(s[i-1]!='0'){
																																				                    cur = cur + num[i-1];
																																									            } 
																																			            num[i] = cur;
																																						        }
																						        return num[len];
																								    }
};
