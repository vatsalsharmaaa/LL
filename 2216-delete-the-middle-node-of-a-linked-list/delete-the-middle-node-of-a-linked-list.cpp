class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head ==NULL || head->next ==NULL){
            return NULL;
        }
        ListNode * prevslow =NULL;
         ListNode * slow =head;
          ListNode * fast=head;

          while(fast!=NULL && fast ->next != NULL){
            prevslow =slow;
            slow =slow->next;
            fast = fast ->next ->next;
          }
          prevslow ->next = slow->next;
          delete(slow);

          return head;
    }
};