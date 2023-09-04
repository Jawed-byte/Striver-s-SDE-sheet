// Concept by Aditya verma

class Solution {
public:
    int solve(TreeNode* root, int &res){
        if(root==NULL)
            return 0;
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        int temp = max(l,r)+1;
        int ans = max(temp,l+r+1);
        res = max(ans,res);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res-1; // substracting 1 since question is asking no of edges as diameter.
    }
};
