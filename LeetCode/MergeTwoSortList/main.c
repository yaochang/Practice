tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *h,*tmp;
        if(l1==NULL && l2==NULL) return NULL;
        if(l1==NULL && l2!=NULL) return l2;
        if(l1!=NULL && l2==NULL) return l1;
        if(l1->val <= l2->val){
            h = l1;
            l1 = l1->next;
        } 
        else{ 
            h = l2;
            l2 = l2->next;
        }
        tmp = h;
        while(l1 || l2){
            if(l1==NULL){
                tmp->next = l2;
                break;
            }
            if(l2==NULL){
                tmp->next = l1;
                break;
            }
            if(l1->val <= l2->val){
                tmp->next = l1;
                tmp = tmp->next;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                tmp = tmp->next;
                l2 = l2->next;
            }
        }
        return h;
    }
};
