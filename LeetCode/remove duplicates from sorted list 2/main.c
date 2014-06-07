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
        ListNode *cur,*h=head;
        int n =0,i;
        while(1){
            n = detect(head);
            if(n==0) return NULL;
            if(n==1){
                cur = head;
                break;
            }
            for(i=0;i<n;i++){
                head = head->next;
            }
        }
        ListNode *tmp;
        while(cur->next){
            n = detect(cur->next);
            tmp = cur->next;
            if(n==1) cur = cur->next;
            if(n>1){
                for(i=0;i<n;i++){
                    tmp = tmp->next;
                }
                cur->next = tmp;
            }
        }
        return head;
    }
    int detect(ListNode *begin){
        if(begin==NULL) return 0;
        ListNode *tmp = begin;
        int number = 1;
        while(tmp->next){
            if(tmp->val == tmp->next->val){
                number++;
                tmp = tmp->next;
            }else{
                break;
            }
        }
        return number;
    }
};
