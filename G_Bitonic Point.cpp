class Solution{
public:
	int findMaximum(int nums[], int n) 
	{
        if(n==1)
          return nums[0];
        if(nums[0]>nums[1])
          return nums[0];
        else if(nums[n-1]>nums[n-2])
          return nums[n-1];
        
        int res=-1;
        
        int i=1;
        int j=n-2;
        
        while(i<=j)
        {
            int m=i+(j-i)/2;
            
            if(nums[m]>nums[m-1] && nums[m]>nums[m+1])
            {
                res=nums[m];
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
