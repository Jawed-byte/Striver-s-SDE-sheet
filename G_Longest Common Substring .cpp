//Recursive
    
    int LCS(string x, string y, int n, int m, int cnt){
        if(n==0 || m==0)
          return cnt;
        if(x[n-1]==y[m-1])
          cnt = LCS(x,y,n-1,m-1,cnt+1);
        cnt = max(cnt,max(LCS(x,y,n,m-1,0),LCS(x,y,n-1,m,0)));
        return cnt;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int cnt=0;
        return LCS(S1,S2,n,m,cnt);
    }
    
    
// Tabulation dp
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int ans=0;
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                 dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(dp[i][j],ans);
                }
                else
                 dp[i][j]=0;
            }
        }
        return ans;
    }
