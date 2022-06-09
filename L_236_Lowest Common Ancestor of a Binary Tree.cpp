/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// By Finding path from root to p and q. And then finding the last common node in the path.

class Solution {
public:
    bool findPath(TreeNode* root, vector<TreeNode*> &path, TreeNode* n){
        if(root==NULL)
            return false;
        path.push_back(root); //finding path
        if(root==n)
            return true;
        if(findPath(root->left,path,n) || findPath(root->right,path,n))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        if(!findPath(root,path1,p) || !findPath(root,path2,q))
            return NULL;
        TreeNode* ans = NULL;
        for(int i=0;i<path1.size() && i<path2.size();i++){
            if(path1[i]==path2[i])
                ans=path1[i];
        }
        return ans;
    }
};

// Recursive Solution

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)
            return NULL;
        if(root==p || root==q)
            return root;
        TreeNode* LCA1 = lowestCommonAncestor(root->left,p,q);
        TreeNode* LCA2 = lowestCommonAncestor(root->right,p,q);
        if(LCA1!=NULL && LCA2!=NULL)
            return root;
        if(LCA1!=NULL)
            return LCA1;
        else
            return LCA2;
    }
};
