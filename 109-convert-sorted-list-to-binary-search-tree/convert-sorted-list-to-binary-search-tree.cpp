class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr){
            return NULL;
        }
        if(head->next==nullptr){
            return new TreeNode(head->val);
        }
        ListNode *slow =head;
        ListNode *fast=head;
        ListNode *slow_prev=NULL;

        while(fast!=NULL && fast->next!=NULL){
            slow_prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode *root= new TreeNode(slow->val); //middle wala root ban gaya

        slow_prev->next=NULL; //disconnect krdia slow k pehle ki list
        root->left=sortedListToBST (head);
        root->right= sortedListToBST(slow->next);

        return root;
    }
};