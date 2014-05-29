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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        if(root==NULL) return 0;
        sumLeaf(root,sum);
        return sum;
    }
    void sumLeaf(TreeNode* root, int& sum){
    	if(root->left == NULL && root->right == NULL){
    		sum = sum + root->val;
    		return;
    	}
    	if(root->left){
    		(root->left)->val = root->val * 10 + (root->left)->val;
    		sumLeaf(root->left,sum);
    	}
    	if(root->right){
    		(root->right)->val = root->val * 10 + (root->right)->val;
    		sumLeaf(root->right,sum);
    	}
    }
};