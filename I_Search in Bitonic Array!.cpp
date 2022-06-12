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
    int binarySearch(vector<int>&arr,int l,int r,int x) 
    { 
      if(r>= l) 
      { 
        int m=l+(r-l)/2; 
        if(arr[m]==x) 
            return m;
        if(arr[m]>x) 
            return binarySearch(arr,l,m-1,x); 
        return binarySearch(arr,m+1,r,x); 
      } 
    return -1; 
    } 
    int binarySearch2(vector<int>&arr,int l,int r,int x) 
    { 
      if(r>= l) 
      { 
        int m=l+(r-l)/2; 
        if(arr[m]==x) 
            return m;
        if(arr[m]<x) 
            return binarySearch2(arr,l,m-1,x); 
        return binarySearch2(arr,m+1,r,x); 
      } 
    return -1; 
    } 
    
    
int Solution::solve(vector<int> &A, int B) 
{
    int index=findPeakElement(A);
        int i1=binarySearch(A,0,index-1,B);
        int i2=binarySearch2(A,index,A.size()-1,B);
            if(i1!=-1)
                return i1;
            else if(i2!=-1)
                return i2;
            else
                return -1;

}
