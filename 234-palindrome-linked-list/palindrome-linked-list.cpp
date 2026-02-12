class Solution {
public:
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;

    
    while (fast && fast->next) {
        fast = fast->next->next;

        ListNode *nextNode = slow->next; // save next
        slow->next = prev;               // reverse link
        prev = slow;                     // move prev
        slow = nextNode;                 // move slow
    }

    // if odd length.....skip middle node
    if (fast) {
        slow = slow->next;
    }

    
    while (prev && slow) {
        if (prev->val != slow->val) return false;
        prev = prev->next;
        slow = slow->next;
    }

    return true;
}
};