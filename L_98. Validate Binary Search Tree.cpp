class Solution {
public:
    bool solve(TreeNode* root, long l, long m){
        if(root == NULL)
            return true;
        if(root->val <= l || root->val >=m)
            return false;
        else
            return solve(root->left,l,root->val) && solve(root->right,root->val,m);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return solve(root,LONG_MIN,LONG_MAX);
    }
};
