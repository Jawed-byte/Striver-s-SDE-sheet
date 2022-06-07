// Brute Force -> Using unordered_set

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>s;
        while(head){
            if(s.find(head)!=s.end())
                return true;
            else
                s.insert(head);
            if(head)
                head = head->next;
        }
        return false;
    }
};

// using slow and fast pointer.

class Solution{
public:
    bool hasCycle(ListNode *head){
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
