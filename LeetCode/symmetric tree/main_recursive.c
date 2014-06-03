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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        return judge(root->left,root->right);
    }
    bool judge(TreeNode *left,TreeNode *right){
        if(left==NULL && right==NULL){
            return true;
        }
        if(left && right){
            if(left->val == right->val){
                if(judge(left->left,right->right) && judge(left->right,right->left)){
                    return true;
                }else{
                    return false;
                }   
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
};
