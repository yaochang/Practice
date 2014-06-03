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
        queue<TreeNode*> qleft;
        queue<TreeNode*> qright;
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        else if(root->left && root->right){
            if(root->left->val == root->right->val){
                qleft.push(root->left);
                qright.push(root->right);
            }else{
                return false;
            }
        }else{
            return false;
        }
        TreeNode *left,*right;
        while(!qleft.empty()){
            left = qleft.front();
            qleft.pop();
            right = qright.front();
            qright.pop();
            if(left->left){
                if(right->right){
                    if(left->left->val == right->right->val){
                        qleft.push(left->left);
                        qright.push(right->right);
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else if(right->right){
                return false;
            }
            
            if(left->right){
                if(right->left){
                    if(left->right->val == right->left->val){
                        qleft.push(left->right);
                        qright.push(right->left);
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }else if(right->left){
                return false;
            }
        }
        return true;
    }
};
