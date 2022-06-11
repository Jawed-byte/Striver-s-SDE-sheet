class Solution {
public:
    int widthOfBinaryTree(TreeNode* root){
        if(root==NULL) 
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        long ans=0;
        while(!q.empty())
        {
            int n = q.size();
            long start = q.front().second;
            long end = q.back().second;
            ans = max(ans, end - start + 1);
            for(int i=0; i<n; i++)
            {
                pair<TreeNode *, int> p = q.front();
                TreeNode *cur = p.first;
                long index = p.second;
                q.pop();
                if(cur->left) 
                    q.push({cur->left, 2*index+1});
                if(cur->right)
                    q.push({cur->right, 2*index+2});
            }
        }
        return ans;
    }
};
