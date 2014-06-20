ass Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<int> tmp;
        vector<vector<int> > res;
        std::sort(num.begin(),num.end());
        int len = num.size();
        if(len<4) return res;
        int i,j,start,end;
        int subtarget;
        int sum;
        for(i=0;i<len;i++){
            tmp.push_back(num[i]);
            subtarget = target - num[i];
            for(j=i+1;j<len;j++){
                start = j+1;
                end = len-1;
                tmp.push_back(num[j]);
                while(start < end){
                    sum = num[j] + num[start] + num[end];
                    if(subtarget == sum){
                        tmp.push_back(num[start]);
                        tmp.push_back(num[end]);
                        res.push_back(tmp);
                        tmp.pop_back();
                        tmp.pop_back();
                        while(start<len-1 && num[start]==num[start+1]) start++;
                        start++;
                    }else if(subtarget > sum){
                        start++;
                    }else{
                        end--;
                    }
                }
                tmp.pop_back();
                while(j<len-1 && num[j]==num[j+1]) j++;
            }
            tmp.pop_back();
            while(i<len-1&&num[i]==num[i+1]) i++;
        }
        return res;
    }
};
