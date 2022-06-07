/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* ----------- Brute Force -------------------

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>s;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(s.find(temp)!=s.end())
                return temp;
            else
                s.insert(temp);
            temp=temp->next;
        }
        return NULL;
    }
};

----------------------------------------------*/

// Using slow & fast pointers

class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                while(slow!=entry){
                   slow = slow->next;
                   entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};
