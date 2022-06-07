
// Brute Force -> By copying elements into an array.

class Solution{
public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int s=0;
        int e=arr.size()-1;
        while(e>s){
            if(arr[s]!=arr[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
};


class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next  = NULL;
        while(head!=NULL){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head){
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};
