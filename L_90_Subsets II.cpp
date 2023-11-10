class Solution {
public:
    void backtrack(set<vector<int>> &ans, vector<int>& nums, vector<int>& temp, int start)
    {
        for(int i=start;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            ans.insert(temp);
            backtrack(ans,nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set<vector<int>> s;
        vector<int> temp;
        s.insert(temp);
        backtrack(s,nums,temp,0);
        vector<vector<int>> ans;
        ans.insert(ans.end(),s.begin(),s.end());
        return ans;      
    }
};
