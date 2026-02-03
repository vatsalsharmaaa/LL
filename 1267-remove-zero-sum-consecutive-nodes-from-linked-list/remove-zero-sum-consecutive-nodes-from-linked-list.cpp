class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        int prefixSum=0;
        mp[0]=dummy;  
        while(head!=NULL){
            prefixSum+=head->val;
            if(mp.find(prefixSum)!=mp.end()){
                //delete wala part
                ListNode *start=mp[prefixSum];
                ListNode *temp=start;
                int psum = prefixSum;
                while(temp!=head){

                    temp=temp->next;
                    psum+=temp->val;

                    if(temp!=head){
                    mp.erase(psum);
                }
                start->next=head->next;     
                }
            }
            else{
                mp[prefixSum]=head;
            }
            head=head->next;
        }      
        return dummy->next;
    }
};