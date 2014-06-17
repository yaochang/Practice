ass Solution {
	public:
		    int atoi(const char *str) {
				        queue<char> number;
						        char max[11]="2147483647";
								        char min[11]="2147483648";
										        int len = strlen(str);
												        bool eli = false;
														        bool num = false;
																        for(int i=0;i<len;i++){
																			            if(str[i]==' '||str[i]=='\t') {
																							                if(num == true) break;
																											                continue;
																															            }
																						            if(str[i]=='-'||str[i]=='+'){
																										                if(num==true) return 0;
																														                number.push(str[i]);
																																		                num = true;
																																						            }else if(str[i]>='0'&&str[i]<='9'){
																																										                number.push(str[i]);
																																														                eli = true;
																																																		                num = true;
																																																						            }
																									            else{
																													                if(eli == true) break;
																																	                else return 0;
																																					            }
																												            
																												        }
																		        char tmp;
																				        int pn;
																						        tmp = number.front();
																								        if(tmp=='-'){
																											            pn = -1;
																														            number.pop();
																																	        }else if(tmp=='+'){
																																				            pn = 1;
																																							            number.pop();
																																										        }else{
																																													            pn = 1;
																																																        }
																										        int res = 0;
																												        int index = 0;
																														        bool right = false;
																																        if(number.size()==0) return 0;
																																		        if(number.size() < 10){
																																					            while(!number.empty()){
																																									                tmp = number.front();
																																													                number.pop();
																																																	                res = res * 10 + tmp-'0';
																																																					            }
																																								            return res*pn;
																																											        }else if(number.size()>10){
																																														            if(pn==1) return 2147483647;
																																																	            else return -2147483648;
																																																				        }else{
																																																							            while(!number.empty()){
																																																											                tmp = number.front();
																																																															                number.pop();
																																																																			                if(pn==1){
																																																																								                    if(right==false && tmp > max[index]) return 2147483647;
																																																																													                    else{
																																																																																			                        res = res * 10 + tmp - '0';
																																																																																									                        if(tmp != max[index]) right = true;
																																																																																															                    }
																																																																																		                }else{
																																																																																							                    if(right==false && tmp > min[index]) return -2147483648;
																																																																																												                    else{
																																																																																																		                        res = res * 10 + tmp - '0';
																																																																																																								                        if(tmp != min[index]) right = true;
																																																																																																														                    }
																																																																																																	                }
																																																																							                index++;
																																																																											            }
																																																										            if(right == true) return res*pn;
																																																													            else{
																																																																	                if(pn==1) return 2147483647;
																																																																					                else return -2147483648;
																																																																									            }
																																																																        }
																																				    }
};
