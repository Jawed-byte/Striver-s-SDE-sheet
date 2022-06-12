class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minh;
        ListNode* head = NULL;
        ListNode* curr = NULL;
        int n = lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)
                minh.push({lists[i]->val,lists[i]});
        }
        while(!minh.empty()){
            ListNode* temp = minh.top().second;
            minh.pop();
            if(head==NULL)
                head=curr=temp;
            else{
                curr->next=temp;
                curr=temp;
            }
            if(temp->next!=NULL){
                temp = temp->next;
                minh.push({temp->val,temp});
            }
        }
        return head;
    }
};
