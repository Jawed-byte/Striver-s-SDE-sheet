bool findPath(TreeNode* root, vector<int> &path, int n){
    if(root==NULL)
        return false;
    path.push_back(root->val); //finding path
    if(root->val==n)
        return true;
    if(findPath(root->left,path,n) || findPath(root->right,path,n))
        return true;
    path.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    if(A==NULL)
      return res;
    findPath(A,res,B);
    return res;
}
