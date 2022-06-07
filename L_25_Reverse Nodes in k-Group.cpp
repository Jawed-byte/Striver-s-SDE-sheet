class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev=dummy, *curr=dummy, *next=dummy;
        int len=0;
        while(curr->next!=NULL){
            curr=curr->next;
            len++;
        }
        while(len>=k){
            curr = prev->next;
            next = curr->next;
            for(int i=1;i<k;i++){
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            len-=k;
        }
        return dummy->next;
    }
};
