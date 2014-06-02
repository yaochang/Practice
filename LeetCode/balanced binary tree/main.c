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
    bool judge(int a,int b){
	if( abs(a-b)<=1) return true;
else return false;	
	}
    bool isBalanced(TreeNode *root) {
        if(root==NULL) return true;
	TreeNode* left,*right;
	left = root->left;
	right = root->right;
	int l=0,r=0;
	bool retleft,retright;
	if(left){ retleft=isBalanced(left); l = left->val;}
	if(right) {retright=isBalanced(right);r = right->val;}
	if(left==NULL && right==NULL){
		root->val = 1;
		return true;	
	}
	if( l > r){ root->val = l+1;}
	else{root->val = r+1;}
	if(judge(l,r) && retleft && retright) return true;
	else return false;
	
    }
};
