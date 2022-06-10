class Solution {
public:
    int solve(TreeNode* root, int &k){
        if(root==NULL)
            return 0;
        int left = solve(root->left,k);
        if(left)
            return left;
        k-=1;
        if(k==0)
            return root->val;
        int right = solve(root->right,k);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        return solve(root,k);
    }
};
