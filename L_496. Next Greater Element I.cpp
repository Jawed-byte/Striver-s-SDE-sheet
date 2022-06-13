class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>s;
        for(int i=nums2.size()-1;i>=0;i--){
            int ele = nums2[i];
            while(!s.empty() && s.top()<=ele)
             s.pop();
            int res = (s.empty())?-1:s.top();
            mp.insert({ele,res});
            s.push(ele);
        }
        vector<int>ans;
        for(auto x: nums1)
            ans.push_back(mp[x]);
        return ans;
    }
};
