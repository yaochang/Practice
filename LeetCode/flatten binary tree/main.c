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
    TreeNode* cur = NULL;
    void flatten(TreeNode *root) {
        if(root==NULL) return;	
	TreeNode* left = root->left;
	TreeNode* right = root->right;
	if(cur==NULL){
		cur = root;
		cur->left = NULL;	
	}else{
		cur->left = NULL;
		cur->right = root;
		cur = root;	
	}
	flatten(left);
	flatten(right);
    }
};
