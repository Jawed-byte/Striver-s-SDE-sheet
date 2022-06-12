class Solution{
public:	
	int findKRotation(int nums[], int n) 
	{
	    int i=0;
        int j=n-1;
        int ans=-1;
        while(i<=j)
        {
            int m=i+(j-i)/2;
            int nxt=(m+1)%n;
            int prv=(m-1+n)%n;
            if(nums[m]<=nums[nxt] && nums[m]<=nums[prv])
            {
                ans=m;
                break;
            }
            else if(nums[i]<=nums[m] && (!(nums[m]<=nums[j])))
                i=m+1;
            else
                j=m-1;
        }
        return ans;
	}

};
