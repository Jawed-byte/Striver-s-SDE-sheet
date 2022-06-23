class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=n-1;
        while(l<=r){
            int m = l+(r-l)/2;
            int prev = (m-1+n)%n;
            int next = (m+1)%n;
            if(nums[prev] >= nums[m] && nums[next] >= nums[m])
                return nums[m];
            else if(nums[l] <= nums[m] && nums[m] >= nums[r])
                l = m+1;
            else
                r = m-1;
        }
        return -1;
    }
};
