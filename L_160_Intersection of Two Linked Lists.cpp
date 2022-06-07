

// Brute Force 

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode* ha=headA;
        while(ha){
            for(ListNode* hb=headB;hb;hb=hb->next){
                if(ha==hb){
                    return ha;
               }
            }
            ha=ha->next;
        }
        return NULL;
    }
};

// Hashing Solution o(n) time & space

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s;
        while(headA){
            s.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(s.find(headB)!=s.end())
                return headB;
            headB=headB->next;
        }
        return NULL;
    }
};

// By finding the lenghths 

class Solution {
public:
    int len1=0,len2=0;
    struct ListNode* h1 = new ListNode();
    struct ListNode* h2 = new ListNode();
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        h1 = headA;
        h2 = headB;
        while(h1){
            len1++;
            h1 = h1->next;
        }
        while(h2){
            len2++;
            h2 = h2->next;
        }
        h1 = headA;
        h2 = headB;
        if ((len1==0)||(len2==0))
            return NULL;
        while(len1!=len2){
            if(len1>len2){
                h1 = h1->next;
                len1--;
            }
            if(len2>len1){
                h2 = h2->next;
                len2--;
            }
        }
        while(h1&&h2){
            if((h1 == h2)&&(h1->next == h2->next))
                return h1;
            h1 = h1->next;
            h2 = h2->next;
        }
        return NULL;
    }
};

// Best Solution

class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode *a = headA;
        ListNode *b = headB;
        while(a!=b){
            a = a == NULL?headB:a->next;
            b = b == NULL?headA:b->next;
        }
        return a;
    }
};
