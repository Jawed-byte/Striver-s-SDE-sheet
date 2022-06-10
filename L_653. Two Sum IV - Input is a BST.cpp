class Solution {
public:
    void inorder(TreeNode* root,vector<int> &vec){
        if(root==NULL)
            return;
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root,vec);
        int n=vec.size();
        int i=0,j=n-1;
        while(i<j){
            if(vec[i]+vec[j]==k)
                return true;
            else if(vec[i]+vec[j]<k){
                i++;
            }
            else
                j--;
        }
        return false;
    }
};
