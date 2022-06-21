// Recursive 
  
    int knapSack(int n, int w, int val[], int wt[])
    {
       if(n==0 || w==0)
          return 0;
       if(wt[n-1]<=w)
          return max(val[n-1]+knapSack(n,w-wt[n-1],val,wt),knapSack(n-1,w,val,wt));
       else if(wt[n-1]>w)
          return knapSack(n-1,w,val,wt);
    }

// Memoization
    
    int solve(int w, int wt[], int val[], int n,vector<vector<int>> &mem)
    {
       if(n==0 || w==0)
         return 0;
       if(mem[n-1][w]!=-1)
         return mem[n-1][w];
       if(wt[n-1]<=w)
         return mem[n-1][w]=max(val[n-1]+solve(w-wt[n-1],wt,val,n,mem),
                                    solve(w,wt,val,n-1,mem));
       if(wt[n-1]>w)
         return mem[n-1][w]=solve(w,wt,val,n-1,mem);
    }
    int knapSack(int n,int w,int val[],int wt[]) 
    {
       vector<vector<int>> mem(1001,vector<int>(1001,-1));
       return solve(w,wt,val,n,mem);
    }

// Tabulation dp
    
    int knapSack(int n, int w, int val[], int wt[]){
        int dp[n+1][w+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                if(i==0 || j==0)
                  dp[i][j]=0;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<w+1;j++){
                if(wt[i-1]<=j)
                    dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][w];
    }
