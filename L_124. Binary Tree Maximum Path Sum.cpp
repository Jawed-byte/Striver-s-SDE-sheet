class Solution {
public:
    int height(TreeNode* node, int &mx){
        if(node == NULL)
            return 0;
        int left = max(0,height(node->left,mx));
        int right = max(0,height(node->right,mx));
        mx = max(mx,left+right+node->val);
        return max(left,right)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        height(root,mx);
        return mx;
    }
};
