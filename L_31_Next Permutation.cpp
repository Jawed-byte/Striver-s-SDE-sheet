/* Generating all possible permutations of the array. And then finding the next permutation of the given array.*/

/*class Solution{
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int idx){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(idx!=i && nums[i]==nums[idx])
                continue;
            swap(nums[i],nums[idx]);
            solve(nums,ans,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    void nextPermutation(vector<int>& nums){
        vector<vector<int>> ans;
        solve(nums,ans,0);
        sort(ans.begin(),ans.end());
        int done=0;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==nums){
                nums=ans[i+1];
                done=1;
                break;
            }
        }
        if(done==0)
            nums=ans[0];
    }
};*/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k,l;
        int n=nums.size();
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0)
            reverse(nums.begin(),nums.end());
        else{
        for(l=n-1;l>k;l--){
            if(nums[l]>nums[k])
                break;
        }
        swap(nums[l],nums[k]);
        reverse(nums.begin()+k+1,nums.end());
        }
    }
};
