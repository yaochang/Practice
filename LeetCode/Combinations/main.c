ass Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> sample;
        vector<vector<int> >res;
        vector<int> tag;
        if(n==0 || k==0 ||k>n) return res;
        generate(res,sample,n,k,1);
        return res;
    }
    void generate(vector<vector<int> >&res, vector<int>&sample, int n, int k, int deep){
        if(sample.size()==k){
            res.push_back(sample);
            return;
        }
        int i;
        for(i=deep;i<=n;i++){
            sample.push_back(i);
            generate(res,sample,n,k,i+1);
            sample.pop_back();
        }
    }
};
