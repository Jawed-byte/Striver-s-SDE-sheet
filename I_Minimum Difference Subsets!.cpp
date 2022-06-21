int Solution::solve(vector<int> &A) {
    int n=A.size();
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=A[i];
    int range=sum;
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    dp[i][0]=1;
    for(int j=1;j<sum+1;j++)
    dp[0][j]=0;
    for(int i=1;i<n+1;i++)
     for(int j=1;j<sum+1;j++)
     {
          if(A[i-1]<=j)
            dp[i][j]=dp[i-1][j-A[i-1]]||dp[i-1][j];
          else
            dp[i][j]=dp[i-1][j];
     }
     vector<int>v;
     for(int j=0;j<=sum/2;j++)
     {
         if(dp[n][j]==1)
         v.push_back(j);
     }
     int mn=INT_MAX;
     for(int i=0;i<v.size();i++)
     mn=min(mn,range-2*v[i]);
     return mn;
}
