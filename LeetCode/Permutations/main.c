class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int len = num.size();
        vector<int> tag;
        for(int i=0;i<len;i++){
            tag.push_back(0);
        }
        vector<int> sample;
        vector<vector<int> > res;
        if(len == 0) return res;
        permutation(res,num,sample,tag,0,len);
        return res;
    }
    void permutation(vector<vector<int> >&res,vector<int>&num,vector<int>&sample,vector<int>&tag,int deep, int len){
        if(deep==len){
            res.push_back(sample);
            return;
        }
        for(int i=0;i<len;i++){
            if(tag[i]==0){
                tag[i]=1;
                sample.push_back(num[i]);
                permutation(res,num,sample,tag,deep+1,len);
                sample.pop_back();
                tag[i]=0;
            }
        }
    }
};
