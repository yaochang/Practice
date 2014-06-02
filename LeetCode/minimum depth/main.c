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
    int minDepth(TreeNode *root) {
        int min = 1000000;
	int cur = 0;
	if(root==NULL) return 0;
	search(root,min,cur);
    return min;
    }
    void search(TreeNode* root,int& min, int cur){
	if(root==NULL) return;
	TreeNode *left,*right;
	left = root->left;
	right = root->right;
	if(left==NULL && right==NULL){
		if(min>cur+1) min = cur+1;	
	}
	search(left,min,cur+1);
	search(right,min,cur+1);
		
    }
};
