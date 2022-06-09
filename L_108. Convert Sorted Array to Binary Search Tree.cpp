class Solution {
public:
    TreeNode* solve(vector<int> &nums, int l, int h){
        if(l<=h){
            int mid = l+(h-l)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = solve(nums,l,mid-1);
            root->right = solve(nums,mid+1,h);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
