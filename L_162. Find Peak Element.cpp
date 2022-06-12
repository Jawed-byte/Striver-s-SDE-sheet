class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
          return 0;
        else if(nums[n-1]>nums[n-2])
          return n-1;
        
        int res=-1;
        
        int i=1;
        int j=n-2;
        
        while(i<=j)
        {
            int m=i+(j-i)/2;
            
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
            {
                res=m;
                break;
            }
            else if(nums[m-1]>nums[m])
                j=m-1;
            else
                i=m+1;
        }
        return res;
    }
};
