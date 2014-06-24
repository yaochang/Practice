class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int count=0;
        ListNode *del=NULL,*pre=NULL,*h;
        h = head;
        while(head){
            count++;
            if(count==n){
                del = h;
            }
            if(count>n){
                pre = del;
                del = del->next;
            }
            head = head->next;
        }
        if(pre==NULL){
            return h->next;
        }else{
            pre->next = del->next;
        }
        return h;
    
    }
};
