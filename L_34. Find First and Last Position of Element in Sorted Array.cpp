class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, r=n-1;
        vector<int>res(2,-1);
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target){
                res[0] = m;
                r = m-1;
            }
            else if(nums[m]<target)
                l = m+1;
            else
                r = m-1;
        }
        l = 0, r = n-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] == target){
                res[1] = m;
                l = m+1;
            }
            else if(nums[m]<target)
                l=m+1;
            else
                r=m-1;
        }
        return res;
    }
};
