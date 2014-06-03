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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL && q==NULL) return true;
        queue<TreeNode*> first;
        queue<TreeNode*> second;
        first.push(p);
        second.push(q);
        TreeNode *a,*b;
        while(!first.empty()){
            a = first.front();
            first.pop();
            b = second.front();
            second.pop();
            if(a && b){
                if(a->val != b->val) return false;
                else{
                    first.push(a->left);
                    first.push(a->right);
                    second.push(b->left);
                    second.push(b->right);
                }
            }else if(a==NULL && b==NULL){
                
            }else{
                return false;
            }
        }
        return true;
    }
};
