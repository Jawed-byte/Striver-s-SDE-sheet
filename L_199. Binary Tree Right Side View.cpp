/* Recursive

class Solution{
public:
    void solve(TreeNode* node, int level, vector<int> &res){
        if(node==NULL)
            return;
        if(level==res.size())
            res.push_back(node->val);
        solve(node->right,level+1,res);
        solve(node->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root){
        vector<int> res;
        solve(root,0,res);
        return res;
    }
};

*/

// Iterative 

class Solution {
public:
    vector<int> levelOrder(TreeNode* root){
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        if(root==NULL)
            return ans;
        while(1){
            int size=q.size();
            if(size==0)
                return ans;
            int data=0;
            while(size>0){
                TreeNode* temp = q.front();
                q.pop();
                data = temp->val;
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
                size--;
            }
            ans.push_back(data);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        res = levelOrder(root);
        return res;
    }
};
