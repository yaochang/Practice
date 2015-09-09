tion for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        unordered_map<RandomListNode*,RandomListNode*> mapping;
        RandomListNode *h = new RandomListNode(head->label);
        RandomListNode *tmp = head;
        RandomListNode *tmpH = h;
        mapping[head] = h;
        while(tmp->next){
            RandomListNode *t = new RandomListNode(tmp->next->label);
            tmpH->next = t;
            mapping[tmp->next] = tmpH->next;
            tmp = tmp->next;
            tmpH = tmpH->next;
        }
        tmp = head;
        tmpH = h;
        while(tmp){
            if(tmp->random){
                mapping[tmp]->random = mapping[tmp->random];
            }
            tmp=tmp->next;
        }
        return h;
    }
};
