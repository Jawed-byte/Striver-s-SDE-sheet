// Recursive

class Solution{
public:
 void solve(Node* node, int level, vector<int> &res){
     if(node==NULL)
       return;
     if(level==res.size())
       res.push_back(node->data);
     solve(node->left,level+1,res);
     solve(node->right,level+1,res);
 }
 vector<int> leftView(Node *root)
 {
    vector<int> res;
    solve(root,0,res);
    return res;
 }
};

// Level Order Traversal

class Solution{
  vector<int> levelOrder(Node* root){
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        if(root==NULL)
            return ans;
        while(1){
            int size=q.size();
            if(size==0)
                return ans;
            int data=0;
            while(size>0){
                Node* temp = q.front();
                q.pop();
                data = temp->data;
                if(temp->right!=NULL)
                    q.push(temp->right);
                if(temp->left!=NULL)
                    q.push(temp->left);
                size--;
            }
            ans.push_back(data);
        }
        return ans;
    }
vector<int> leftView(Node *root)
{
   vector<int> res;
   res = levelOrder(root);
   return res;
}

};
