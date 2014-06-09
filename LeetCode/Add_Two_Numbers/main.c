tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==NULL && l2==NULL) return NULL;
        ListNode *head,*cur;
        bool tag = false;
        int left,right,add=0,res;
        while(l1 || l2){
            left = 0;
            right = 0;
            if(l1){
                left = l1->val;
                l1=l1->next;
            }
            if(l2){
                right = l2->val;
                l2=l2->next;
            }
            res = left+right+add;
            if(res>=10){
                add = 1;
                res = res%10;
            }else{
                add = 0;
            }
            ListNode *tmp = new ListNode(res);
            if(tag==false){
                tag = true;
                head = tmp;
                cur = tmp;
            }else{
                cur->next = tmp;
                cur = cur->next;
            }
        }
        if(add>0){
            ListNode *t = new ListNode(add);
            cur->next = t;
        }
        return head;
    }
};
