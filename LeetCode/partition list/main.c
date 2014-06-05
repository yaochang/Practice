tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        int lindex=0,sindex=0;
        ListNode *h = head;
        ListNode *s,*l;
        int index=0;
        while(head){
            index++;
            if(head->val < x && sindex==0){
                s = head;
                sindex = index;
            }
            if(head->val >=x && lindex==0){
                l = head;
                lindex = index;
            }
            if(lindex!=0 && sindex!=0) break;
            head = head->next;
        }
        head = h;
        if(sindex==0 || lindex==0) return h;
        ListNode *tmp;
        ListNode *t;
        if(sindex > lindex){
            tmp = s->next;
            s->next = l;
            while(l->next != s){
                l = l->next;
            }
            l->next = tmp;
            head = s;
        }
        else{
            while(s->next!=l){
                s = s->next;
            }
        }
        while(l){
            if(l->next==NULL) break;
            if(l->next->val >= x){
                l = l->next;
            }else{
                tmp = l->next->next;
                t = s->next;
                s->next = l->next;
                s=s->next;
                s->next = t;
                l->next = tmp;
            }
        }
        return head;
    }
};
