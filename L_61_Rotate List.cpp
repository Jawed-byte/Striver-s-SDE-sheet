
// Brute force -

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int len=0;
        ListNode *curr = head;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        k=k%len;
        for(int i=0;i<k;i++){
            ListNode *temp = head;
            while(temp->next->next!=NULL)
                temp=temp->next;
            ListNode *newHead = temp->next;
            newHead->next = head;
            temp->next = NULL;
            head = newHead;
        }
        return head;
    }
};

// Optimized

class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        if(head==NULL || head->next==NULL || k==0)
            return head;
        ListNode *curr = head;
        int len = 1;
        while(curr->next!=NULL)
            curr = curr->next, len++;
        curr->next = head;
        k = k%len;
        k = len-k;
        while(k--)
            curr = curr->next;
        head = curr->next;
        curr->next=NULL;
        return head;
        
    }
};
