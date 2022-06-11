// Recursive

class Solution {
public:
    void solve(TreeNode* node, vector<int>& inorder){
        if(node==NULL)
            return;
        solve(node->left, inorder);
        inorder.push_back(node->val);
        solve(node->right, inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        solve(root, inorder);
        return inorder;
    }
};


// Iterative

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(1){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty())
                    break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};


// Morris Inorder Traversal

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> inorder;
        TreeNode* node = root;
        while(node!=NULL){
            if(node->left==NULL){
                inorder.push_back(node->val);
                node = node->right;
            }
            else{
                TreeNode* l = node->left;
                while(l->right && l->right!=node){
                    l = l->right;
                }
                if(l->right == NULL){
                    l->right = node;
                    node = node->left;
                }
                else{
                    l->right = NULL;
                    inorder.push_back(node->val);
                    node = node->right;
                }
            }
        }
        return inorder;
    }
};
