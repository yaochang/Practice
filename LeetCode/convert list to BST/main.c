/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
ListNode* head = NULL;
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        this->head = head;
        ListNode* tmp = head;
        int length = 0;
        while(tmp != NULL){
            length++;
            tmp = tmp->next;
        }
        TreeNode* root = construct(0,length-1);
        return root;
    
    }
    TreeNode* construct(int start,int end){
        if(start>end) return NULL;
        TreeNode *root,*left,*right;
        int mid = (start+end)/2;
        left = construct(start,mid-1);
        root = new TreeNode(head->val);
        root->left = left;
        this->head = (this->head)->next;
        root->right = construct(mid+1,end);
        return root;
    }
};
