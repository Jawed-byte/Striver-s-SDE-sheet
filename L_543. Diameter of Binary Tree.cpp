class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        height(root,d);
        return d;
    }
private:
    int height(TreeNode* node, int &mx){
        if(node==NULL)
            return 0;
        int lh = height(node->left,mx);
        int rh = height(node->right,mx);
        mx = max(mx,lh+rh);
        return 1+max(lh,rh);
    }
};
