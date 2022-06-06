// Brute Force

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* curr = head;
        int len =0;
        int middle;
        while(curr!= NULL) {
            len++;
            curr = curr->next;
        }
        
        middle=len/2;
        curr = head; 
        
        while(middle--){
            curr = curr->next;
        }
    
    return curr;
    }
};

// Optimal

class Solution{
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast !=NULL && fast->next !=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
