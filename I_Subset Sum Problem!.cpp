/* Recursive 

int knapSack(vector<int> &A, int B, int n){
    if(n==0)
      return B==0;
    if(B==0)
      return 1;
    if(A[n-1]==B)
      return 1;
    else if(A[n-1]<B)
      return knapSack(A,B-A[n-1],n-1) || knapSack(A,B,n-1);
    else
      return knapSack(A,B,n-1);
}
int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    return knapSack(A, B, n);
}

*/

/* Memoization

int knapSack(vector<int> &A, int B, int n, vector<vector<int>> &mem){
    if(n==0)
      return B==0;
    if(B==0)
      return 1;
    if(A[n-1]==B)
      return 1;
    else if(mem[n-1][B]!=-1)
      return mem[n-1][B];
    else if(A[n-1]<B)
      return mem[n-1][B] = knapSack(A,B-A[n-1],n-1,mem) || knapSack(A,B,n-1,mem);
    else
      return mem[n-1][B] = knapSack(A,B,n-1,mem);
}

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<vector<int>> mem(101, vector<int>(100001,-1));
    return knapSack(A, B, n, mem);
}

*/

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int dp[n+1][B+1];
    for(int i=0;i<n+1;i++)
    dp[i][0]=1;
    for(int j=1;j<B+1;j++)
    dp[0][j]=0;
    for(int i=1;i<n+1;i++)
     for(int j=1;j<B+1;j++)
     {
        if(A[i-1]<=j)
          dp[i][j]=dp[i-1][j-A[i-1]]||dp[i-1][j];
        else
          dp[i][j]=dp[i-1][j];
     }
    return dp[n][B];
}
