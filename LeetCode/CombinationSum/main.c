class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> sample;
        generate(res,sample,candidates,0,0,target);
        return res;
        
    }
    void generate(vector<vector<int> >&res,vector<int>&sample,vector<int>&candidates,int index,int current,int target){
        if(current==target){
            res.push_back(sample);
            return;
        }
        if(current > target){
            return;
        }
        int len = candidates.size();
        int i;
        for(i=index;i<len;i++){
            sample.push_back(candidates[i]);
            current = current + candidates[i];
            generate(res,sample,candidates,i,current,target);
            current = current - candidates[i];
            sample.pop_back();
        }
    }
};
