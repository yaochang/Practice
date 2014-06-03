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
    int token = 99999999;
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
       vector<vector<int> > result;
       vector<int> level;
       if(root==NULL) return result;
       stack<TreeNode*> left;
       stack<TreeNode*> right;
       left.push(root);
       int number;
       TreeNode *tmp;
       while(!left.empty() || !right.empty()){
           while(!left.empty()){
               tmp = left.top();
               left.pop();
               level.push_back(tmp->val);
               if(tmp->left) right.push(tmp->left);
               if(tmp->right) right.push(tmp->right);
           }
           if(level.size()>0) result.push_back(level);
           level.clear();
           while(!right.empty()){
               tmp = right.top();
               right.pop();
               level.push_back(tmp->val);
               if(tmp->right) left.push(tmp->right);
               if(tmp->left) left.push(tmp->left);
           }
           if(level.size()>0) result.push_back(level);
           level.clear();
       }
       return result;
    }
};
