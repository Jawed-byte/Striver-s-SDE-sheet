/* Recursive

class Solution {
public:
    int LCS(string x, string y, int n, int m){
        if(n==0 || m==0)
            return 0;
        if(x[n-1]==y[m-1])
            return 1 + LCS(x,y,n-1,m-1);
        else
            return max(LCS(x,y,n,m-1),LCS(x,y,n-1,m));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        return LCS(text1,text2,n,m);
    }
};

*/


/* Memoization

class Solution{
public:
    int LCS(string x, string y, int n, int m, vector<vector<int>> &mem){
        if(n==0 || m==0)
            return 0;
        else if(mem[n-1][m-1]!=-1)
            return mem[n-1][m-1];
        else if(x[n-1]==y[m-1])
            return mem[n-1][m-1] = 1 + LCS(x,y,n-1,m-1,mem);
        else
            return mem[n-1][m-1] = max(LCS(x,y,n,m-1,mem),LCS(x,y,n-1,m,mem));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> mem(1001, vector<int>(1001,-1));
        return LCS(text1,text2,n,m,mem);
    }
};

*/

// Tabulation dp

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        int dp[n+1][m+1];
        for(int i=0;i<n+1;i++)
            dp[i][0]=0;
        for(int j=0;j<m+1;j++)
            dp[0][j]=0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
