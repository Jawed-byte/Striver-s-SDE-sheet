/* Method1 -> Recursive

class Solution {
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

*/

/* Method2 -> Using Stack

class Solution{
public:
    void flatten(TreeNode* root){
        if(root==NULL)
            return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->right!=NULL)
                st.push(node->right);
            if(node->left!=NULL)
                st.push(node->left);
            if(!st.empty())
                node->right = st.top();
            node->left = NULL;
        }
    }
};

*/

// Method3 -> Using Threadeed Binary tree concept same as used in Morris traversal.

class Solution{
public:
    void flatten(TreeNode* root){
        TreeNode* node = root;
        while(node){
            if(node->left){
                TreeNode* prev = node->left;
                while(prev->right)
                    prev = prev->right;
                prev->right = node->right;
				node->right = node->left;
				node->left = NULL;
            }
            node = node->right;
        }
    }
};
