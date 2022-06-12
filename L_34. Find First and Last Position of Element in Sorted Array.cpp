class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int>ans;
        int res1=-1;
        int res2=-1;
        while(i<=j){
            int m=i+(j-i)/2;
            if(nums[m]==target){
                res1=m;
                j=m-1;
            }
            else if(target<nums[m])
                j=m-1;
            else
                i=m+1;
        }
        ans.push_back(res1);
        i=0,j=nums.size()-1;
        while(i<=j){
            int m=i+(j-i)/2;
            if(nums[m]==target){
                res2=m;
                i=m+1;
            }
            else if(target<nums[m])
                j=m-1;
            else
                i=m+1;
        }
        ans.push_back(res2);
        return ans;
    }
};
