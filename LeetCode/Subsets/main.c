class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        std::sort(S.begin(),S.end());
        vector<vector<int> >res;
        vector<int> sample;
        int len = S.size();
        int i;
        for(i=0;i<=len;i++){
            generate(res,sample,0,i,S);
        }
        return res;
    }
    void generate(vector<vector<int> >&res,vector<int>&sample,int deep,int n,vector<int>&S){
        if(sample.size()==n){
            res.push_back(sample);
            return;
        }
        int len = S.size();
        for(int i=deep+1;i<=len;i++){
            sample.push_back(S[i-1]);
            generate(res,sample,i,n,S);
            sample.pop_back();
        }
    }
};
