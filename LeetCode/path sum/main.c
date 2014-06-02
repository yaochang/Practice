/**p
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
    bool hasPathSum(TreeNode *root, int sum) {
        int curSum = 0;
	if(root==NULL) return false;
	return judge(root,sum,curSum);
    }
    bool judge(TreeNode *root,int sum, int&curSum){
    	TreeNode *left,*right;
	if(root==NULL) return false;
	left = root->left;
	right = root->right;
	curSum = curSum + root->val;
	if(left==NULL && right==NULL && sum==curSum) return true;
	bool retLeft = false, retRight=false;
	retLeft = judge(left,sum,curSum);
	retRight = judge(right,sum,curSum);
	curSum = curSum - root->val;
	return (retLeft||retRight); 
    }
};
