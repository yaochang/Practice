/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int len = num.size();
        if(len==0) return NULL;
        TreeNode *root = construct(num,0,len-1);
        return root;
    }
    TreeNode *construct(vector<int> &num,int start,int end){
        if(start>end) return NULL;
        int mid = (start+end)/2;
        TreeNode *left,*right;
        TreeNode *root = new TreeNode(num[mid]);
        if(start!=end){
            left = construct(num,start,mid-1);
            right = construct(num,mid+1,end);
            root->left = left;
            root->right = right;
        }
        return root;
    }
};
