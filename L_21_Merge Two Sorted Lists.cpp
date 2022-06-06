// Extra space

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* curr = new ListNode();
        ListNode* res = curr;
        while(true){
            if(l1==NULL && l2==NULL)
                break;
            if(l1!=NULL && l2!=NULL){
                if(l1->val <= l2->val){
                    curr->next = l1;
                    l1 = l1->next;
                }
                else{
                    curr->next = l2;
                    l2 = l2->next;
                }
            }
            else if(l1==NULL){
                curr->next = l2;
                l2 = l2->next;
            }
            else if(l2==NULL){
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }
        return res->next;
    }
};


// No extra space

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val > l2->val)
            swap(l1,l2);
        ListNode* res = l1;
        while(l1!=NULL && l2!=NULL){
            ListNode* tmp = NULL;
            while(l1!=NULL && l1->val <= l2->val){
                tmp = l1;
                l1 = l1->next;
            }
            tmp->next=l2;
            swap(l1,l2);
        }
        return res;
    }
};
