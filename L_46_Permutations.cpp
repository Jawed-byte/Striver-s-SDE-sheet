class Solution {
public:
    void backtrack(set<vector<int>> &res, vector<int> &temp, vector<int> &nums){
        if(temp.size()==nums.size())
            res.insert(temp);
        for(int i=0;i<nums.size();i++){
        if(find(temp.begin(),temp.end(),nums[i])==temp.end()){
            temp.push_back(nums[i]);
            backtrack(res,temp,nums);
            temp.pop_back();
         }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> temp;
        backtrack(res,temp,nums);
        vector<vector<int>> ans(res.size(),vector<int>(nums.size()));
        copy(res.begin(), res.end(), ans.begin());
        return ans;
        
    }
};
