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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> level;
        if(root==NULL) return result;
        queue<TreeNode*> q;
        TreeNode *bar = new TreeNode(0);
        TreeNode *tmp;
        int number;
        q.push(root);
        q.push(bar);
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp==bar){
                result.push_back(level);
                level.clear();
                if(!q.empty()){
                    q.push(bar);
                }
            }else{
                level.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        }
        return result;
    }
};
