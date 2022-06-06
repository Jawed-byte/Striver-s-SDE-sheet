/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr = head ;
        int len =  0 ;
        while(curr!=NULL){
            len++ ;
            curr = curr->next ;
        }
        ListNode *prev   ;
        curr = head ;
        len = len - n ;
        if(len == 0){
            head = head->next ;
            return head ;
        }
        while(len>0){ 
            prev = curr ;
            curr = curr->next ;
            len--;
        }
        prev->next = curr->next;
        return head ;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        for(int i=1;i<=n;i++)
            fast=fast->next;
        
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
    }
};
