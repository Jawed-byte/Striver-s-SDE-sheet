int Solution::solve(vector<int> &A) 
{
    int n=A.size();
        if(n==1)
          return A[0];
        if(A[0]>A[1])
          return A[0];
        else if(A[n-1]>A[n-2])
          return A[n-1];
        
        int res=A[n-1];
        
        int i=1;
        int j=n-2;
        
        while(i<=j)
        {
            int m=i+(j-i)/2;
            
            if(A[m]>A[m-1] && A[m]>A[m+1])
            {
                res=A[m];
                break;
            }
            else if(A[m-1]>A[m])
                j=m-1;
            else
                i=m+1;
        }
        return res;
}
