//APPROACH 1 using vectors

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>curr;
        ListNode * temp=head;
        while(temp!=NULL){
            curr.push_back(temp->val);
            temp=temp->next;
        }   
        int n=curr.size();
        int maxi=INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            maxi= max(maxi,curr[i]+curr[j]);
            i++;j--;
        }
        return maxi;
    }
};