//APPROACH 1 using vectors

// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         vector<int>curr;
//         ListNode * temp=head;
//         while(temp!=NULL){
//             curr.push_back(temp->val);
//             temp=temp->next;
//         }   
//         int n=curr.size();
//         int maxi=INT_MIN;
//         int i=0,j=n-1;
//         while(i<j){
//             maxi= max(maxi,curr[i]+curr[j]);
//             i++;j--;
//         }
//         return maxi;
//     }
// };
class Solution {
public:
    int pairSum(ListNode* head) {
       
       ListNode *fast=head;
       ListNode* slow = head;
       while(fast!=NULL &&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

       }
       ListNode * mid=slow;

       //2. reverese second half of ll
        ListNode *prev=NULL;
        ListNode *nextNode=NULL;
        while(mid!=NULL){
            nextNode = mid->next;
            mid->next=prev;
            prev=mid;
            mid=nextNode;
        }
        int result = 0;
        ListNode * curr=head;

        while(prev!=NULL){
            result=max(result,curr->val + prev->val);
            curr=curr->next;
            prev=prev->next;
        }
        return result;



    }
};