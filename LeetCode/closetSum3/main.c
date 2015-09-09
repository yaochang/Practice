ass Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        std::sort(num.begin(),num.end());
        int len = num.size();
        int min = 1000000,res;
        int i,start,end;
        int sum = 0;
        for(i=0;i<len;i++){
            start = i+1;
            end = len-1;
            while(start<end){
                 sum = num[i]+num[start]+num[end];
                 if(sum==target){
                     return sum;
                 }
                 if(sum<target){
                     if(target-sum < min){
                         min = target - sum;
                         res = sum;
                     }
                     start++;
                 }
                 if(sum>target){
                     if(sum-target < min){
                         min = sum - target;
                         res = sum;
                     }
                     end--;
                 }
            }
            while(i<len-1 && num[i]==num[i+1]) i++;
        }
        return res;
    }
};
