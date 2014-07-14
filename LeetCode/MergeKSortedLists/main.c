/*
 *Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
	int n = lists.size();
	if(n==0) return NULL;
 	ListNode *head = NULL;
	head = merge(lists,0,n-1);
	return head; 
    }
    ListNode *merge(vector<ListNode *> &lists, int left, int right){
	if(left == right) return lists[left];
	ListNode *l = NULL;
	ListNode *r = NULL;
	ListNode *head = NULL;
	ListNode *t = NULL;
	if(left+1 == right){
		l = lists[left];
		r = lists[right];
	}else if(left+1 < right){
		int mid = (left+right)/2;
		l = merge(lists,left,mid);
		r = merge(lists,mid+1,right);
	}
	
	if(l==NULL && r==NULL) return NULL;
	if(l==NULL && r) return r;
	if(l && r==NULL) return l;	
	// if l!=NULL and r!=NULL
	if(l->val < r->val){
		head = l;
		l = l->next;
	}else{
		head = r;
		r = r->next;
	}
	t = head;
	while(r || l){
		if(r && l){
			if(l->val < r->val){
				t->next = l;
				l = l->next;
				t = t->next;
			}else{
				t->next = r;	
				r = r->next;
				t = t->next;
			}
		}else if(r==NULL){
			t->next = l;
			break;
		}else if(l==NULL){
			t->next = r;
			break;
		}
	}
	return head;
    }
};
