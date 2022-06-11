// Recursive

class Solution {
public:
    void solve(TreeNode* root, vector<int> &preorder){
        if(root==NULL)
            return;
        preorder.push_back(root->val);
        solve(root->left,preorder);
        solve(root->right,preorder);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        solve(root,preorder);
        return preorder;
    }
};


// Iterative

class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> preorder;
        if(root==NULL)
            return preorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right!=NULL)
                st.push(root->right);
            if(root->left!=NULL)
                st.push(root->left);
        }
        return preorder;
    }
};

// Morris Preorder Traversal

class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> preorder;
        TreeNode* node = root;
        while(node!=NULL){
            if(node->left==NULL){
                preorder.push_back(node->val);
                node = node->right;
            }
            else{
                TreeNode* l = node->left;
                while(l->right && l->right!=node){
                    l = l->right;
                }
                if(l->right == NULL){
                    l->right = node;
                    preorder.push_back(node->val);
                    node = node->left;
                }
                else{
                    l->right = NULL;
                    node = node->right;
                }
            }
        }
        return preorder;
    }
};
