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
    unordered_map<int,int> position;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for(int i=0;i<inorder.size();i++){
            position[inorder[i]] = i;
        }
        if(preorder.size()==0) return NULL;
        int len = preorder.size();
        return construct(preorder,0,len-1,inorder,0,len-1);
    }
    TreeNode *construct(vector<int> &pre,int pre_start,int pre_end,vector<int> &in,int in_start,int in_end){
        if(pre_start>pre_end) return NULL;
        TreeNode *root;
        if(pre_start==pre_end){
            root = new TreeNode(pre[pre_start]);
            return root;
        }
        root = new TreeNode(pre[pre_start]);
        int in_pos = position[pre[pre_start]];
        int leftNum = in_pos - in_start;
        int rightNum = in_end - in_pos;
        root->left = construct(pre,pre_start+1,pre_start+leftNum,in,in_start,in_pos-1);
        root->right = construct(pre,pre_start+leftNum+1,pre_end,in,in_pos+1,in_end);
        return root;
    }
};
