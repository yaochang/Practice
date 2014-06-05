ass Solution {
	public:
		    vector<string> restoreIpAddresses(string s) {
				        vector<string> result;
						        string res;
								        search(result,s,0,4,res);
										        return result;
												    }
			    void search(vector<string>&result,string s,int start,int left,string res){
					        if(left==0 && start==(s.length())){
								            result.push_back(res);
											            return;
														        }
							        if(left==0 && start<s.length()) return;
									        if(start>=s.length()) return;
											        string tmp;
													        string temp = res;
															        for(int i=1;i<=3;i++){
																		           if(start+i-1 >= s.length()) continue;
																				              tmp = s.substr(start,i);
																							             if(i>=2&&tmp[0]=='0') continue;
																										            if(judge(tmp)){
																														               if(left==4){
																																		                      res = tmp;
																																							                 }else{
																																												                    res = res + "." + tmp;
																																																	               }
																																	                  search(result,s,start+i,left-1,res);
																																					                 res = temp;
																																									            }
																													        }
																	    }
				    bool judge(string s){
						        int num = atoi(s.c_str());
								        if(0<=num && num <=255) return true;
										        else return false;
												    }
};
