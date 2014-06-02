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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
	vector<int> path;
	int curSum = 0;
	if(root==NULL) return result;
	search(root,sum,curSum,result,path);
	return result;
    }
    void search(TreeNode* root, int sum, int& curSum,vector<vector<int> >&result,vector<int>& path){
	if(root==NULL) return;
	TreeNode *left,*right;
left = root->left;
	right = root->right;
	curSum = curSum + root->val;
	path.push_back(root->val);
	if(left==NULL&&right==NULL&&curSum==sum){
		result.push_back(path);	
	}
	search(left,sum,curSum,result,path);
	search(right,sum,curSum,result,path);
	curSum = curSum - root->val;
	path.pop_back();	    
    }
};
