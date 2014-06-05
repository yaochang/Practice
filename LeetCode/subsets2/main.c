ass Solution {
	public:
		    vector<vector<int> > subsetsWithDup(vector<int> &S) {
				        std::sort(S.begin(),S.end());
						        vector<vector<int> > result;
								        vector<int> subset;
										        if(S.size()==0) return result;
												        unordered_map<int,int> hashmap;
														        vector<int> keys;
																        int Pre = 1000000000;
																		        for(int i=0;i<S.size();i++){
																					            if(hashmap.find(S[i])==hashmap.end()){
																									                hashmap[S[i]] = 1;
																													            }else{
																																	                hashmap[S[i]] = hashmap[S[i]]+1;
																																					            }
																								            if(S[i]!=Pre){
																												                keys.push_back(S[i]);
																																                Pre = S[i];
																																				            }
																											        }
																				        int level = hashmap.size();
																						        search(level,keys,hashmap,result,subset);
																								        return result;
																										    }
			    void search(int level,vector<int>&keys,unordered_map<int,int>&hashmap,vector<vector<int> >&result,vector<int>&subset){
					        if(level==0){
								            result.push_back(subset);
											            return;
														        }
							        int index = hashmap.size() - level;
									        int cur = keys[index];
											        int i,len = hashmap[cur];
													        for(i=0;i<=len;i++){
																            search(level-1,keys,hashmap,result,subset);
																			            subset.push_back(cur);
																						        }
															        for(i=0;i<=len;i++){
																		            subset.pop_back();
																					        }
																	        return;
																			    }
};
