tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode *h = head;
        while(head->next){
            if(head->val==head->next->val){
                head->next = head->next->next;
            }else{
                head=head->next;
            }
        }
        return h;
    }
};
