class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>maxh;
        for(int i=0;i<nums.size();i++)
            maxh.push({nums[i],i});
        vector<int>v;
        while(maxh.size()>n-k)
        {
            v.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(v.begin(),v.end());
        vector<int>res;
        for(int i=0;i<v.size();i++)
            res.push_back(nums[v[i]]);
        return res;
    }
};
