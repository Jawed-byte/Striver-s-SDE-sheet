class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL)
            return ans;
        int i=0;
        while(1){
            int size=q.size();
            if(size==0)
                return ans;
            vector<int>data;
            while(size>0){
                TreeNode* temp = q.front();
                q.pop();
                data.push_back(temp->val);
                
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                size--;
            }
            i++;
              if(i%2!=0)
                ans.push_back(data);
              else{
                  reverse(data.begin(),data.end());
                  ans.push_back(data);
              }
        }
        return ans;
    }
};
