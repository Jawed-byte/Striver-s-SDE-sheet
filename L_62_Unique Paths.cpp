/*------RECURSIVE SOLUTION----------

class Solution {
public:
    int countPaths(int i, int j, int m, int n){
        if(i==(m-1) && j==(n-1))
            return 1;
        if(i>=m || j>=n)
            return 0;
        else
            return countPaths(i+1,j,m,n)+countPaths(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        return countPaths(0,0,m,n);
    }
};

--------RECURSIVE SOLUTION---------*/


/*------MEMOIZED RECURSIVE SOLUTION ------------

class Solution {
public:
    int countPaths(int i, int j, int m, int n,vector<vector<int>> &mem){
        if(i==(m-1) && j==(n-1))
            return 1;
        if(i>=m || j>=n)
            return 0;
        if(mem[i][j]!=-1)
            return mem[i][j];
        else
            return mem[i][j]=countPaths(i+1,j,m,n,mem)+countPaths(i,j+1,m,n,mem);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(101,vector<int>(101,-1));
        return countPaths(0,0,m,n,mem);
    }
};

--------- MEMOIZED RECURSIVE SOLUTION ------------*/


/*------ Tabulation DP ----------------
class Solution {
public:
    int uniquePaths(int m,int n) {
        int dp[m][n];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 && j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=dp[i][j-1];
                else if(j==0)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

----------- Tabulation DP -------------*/

// Solution using Combination formulla..

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2;
        int r = m-1;
        double res = 1;
        for(int i=1;i<=r;i++)
            res = res*(N-r+i)/i;
        return (int) res;
    }
};
