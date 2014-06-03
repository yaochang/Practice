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
    int token = 10000000;
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> level;
        if(root==NULL) return result;
        stack<int> s;
        queue<TreeNode*> q;
        TreeNode *barrier = new TreeNode(0);
        q.push(root);
        q.push(barrier);
        TreeNode *tmp;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp==barrier){
                if(!q.empty()){
                    s.push(token);
                    q.push(barrier);
                }
            }else{
                s.push(tmp->val);
            }
            if(tmp->right) q.push(tmp->right);
            if(tmp->left) q.push(tmp->left);
        }
        int number;
        while(!s.empty()){
            number = s.top();
            s.pop();
            if(number==token){
                result.push_back(level);
                level.clear();
            }else{
                level.push_back(number);
            }
        }
        result.push_back(level);
        return result;
    }
};
