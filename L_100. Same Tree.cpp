// Method1

class Solution {
public:
    void inorder(TreeNode* node, vector<int>& v){
        if(node!=NULL){
            inorder(node->left,v);
            v.push_back(node->val);
            inorder(node->right,v);
        }
        else
          v.push_back(100000);
    }
    
    void preorder(TreeNode* node, vector<int>& v){
        if(node!=NULL){
            v.push_back(node->val);
            preorder(node->left,v);
            preorder(node->right,v);
        }
        else
            v.push_back(100000);
    } 
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
       vector<int>inp;
        vector<int>inq;
        vector<int>prep;
        vector<int>preq;
        
        inorder(p,inp);
        inorder(q,inq);
        preorder(p,prep);
        preorder(q,preq);
        
        if(inp==inq && prep==preq)
            return true;
        else
            return false;
    }
};

// Method2

class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL)
            return p==q;
        return (p->val==q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
