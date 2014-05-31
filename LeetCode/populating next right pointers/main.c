/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        root->next = NULL;
        subconnect(root);
    }
    void subconnect(TreeLinkNode* root){
    	if(root==NULL) return;
    	if(root->next!=NULL){
    	    if(root->right){
    		    (root->right)->next = (root->next)->left;
    	    }
    	}
    	if(root->left){
            (root->left)->next = (root->right);
    	}
    	subconnect(root->left);
    	subconnect(root->right);

    }
};