class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *preM=NULL,*preN=NULL,*curM=NULL,*curN=NULL,*h=NULL;
        if(head==NULL) return NULL;
        h = head;
        if(m==n) return head;
        int count=0;
        ListNode *pre=NULL,*cur=NULL;
        while(head){
            count++;
            if(count==m-1){
                preM = head;
                head = head->next;
            }else if(count==m){
                curM = head;
                pre = curM;
                head = head->next;
            }else if(count>m && count<n){
                cur = head;
                head = head->next;
                cur->next = pre;
                pre = cur;
            }else if(count==n){
                curM->next = head->next;
                cur = head;
                cur->next = pre;
                if(preM==NULL){
                    h = cur;
                }else{
                    preM->next = cur;
                }
                break;
            }else{
                head = head->next;
            }
        }
        return h;
        
    }
};
