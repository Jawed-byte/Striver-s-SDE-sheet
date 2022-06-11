class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            TreeNode* node= tmp.first;
            int x = tmp.second.first;
            int y = tmp.second.second;
            mp[x][y].insert(node->val);
            if(node->left)
                q.push({node->left,{x-1,y+1}});
            if(node->right)
                q.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>> ans;
        for(auto it1: mp){
            vector<int> vertical;
            for(auto it2: it1.second){
         vertical.insert(vertical.end(),it2.second.begin(),it2.second.end());
            }
            ans.push_back(vertical);
        }
        return ans;
    }
};
