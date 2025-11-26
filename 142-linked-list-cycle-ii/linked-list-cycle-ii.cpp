#include <unordered_set>

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        
        // if(head==NULL) return NULL;

        // unordered_set<ListNode*> s;

        // ListNode* start = head;
        // while(start != NULL){
        //     if(s.count(start)) { 
        //         return start;     // Cycle detected — this is the start node
        //     }
        //     s.insert(start);
        //     start = start->next;
        // }

        // return NULL; // No cycle
        if(head==NULL || (head->next ==NULL)){
            return NULL;
        }
        ListNode * slow =head;
        ListNode * fast =head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(slow!=fast)
        return NULL;

        ListNode *p=head;

        while(p!=slow){
            p=p->next;
            slow =slow->next;
        }
        return p;
    }
};
