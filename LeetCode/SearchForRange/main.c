class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        res = search(A,0,n-1,target);
        return res;
    }
    vector<int> search(int A[],int start,int end,int target){
        vector<int> res;
        if(start>end){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int mid = (start+end)/2;
        vector<int> left,right;
        int l,r;
        if(A[mid] == target){
            left = search(A,start,mid-1,target);
            right = search(A,mid+1,end,target);
            l = left[0];
            r = right[1];
            if(l==-1) l = mid;
            if(r==-1) r = mid;
            res.push_back(l);
            res.push_back(r);
            return res;
        }else if(A[mid]>target){
            res = search(A,start,mid-1,target);   
        }else{
            res = search(A,mid+1,end,target);
        }
    }
};
