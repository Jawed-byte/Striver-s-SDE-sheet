
bool isPalindrome(string s, int i, int j)
{
    if(i==j)
      return true;
    if(i>j)
      return false;
    while(i<j)
    {
        if(s[i]!=s[j])
          return false;
        i++;
        j--;
    }
    return true;
}

/* Recursive 

int solve(string s, int i, int j){
    if(i>=j)
     return 0;
    if(isPalindrome(s,i,j))
     return 0;
    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp = 1+solve(s,i,k)+solve(s,k+1,j);
        mn = min(mn,temp);
    }
    return mn;
}
int Solution::minCut(string A) 
{
      int i=0;
      int j=A.size()-1;
      return solve(A,i,j);
}

*/

// Memoization

int solve(string s, int i, int j,vector<vector<int>> &mem)
{
    if(i>=j)
      return 0;
    if(isPalindrome(s,i,j)==true)
      return 0;
    if(mem[i][j]!=-1)
      return mem[i][j];
    mem[i][j]=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int left,right;
        if(mem[i][k]!=-1)
            left=mem[i][k];
        else
        {
            left=solve(s,i,k,mem);
            mem[i][k]=left;
        }
        if(mem[k+1][j]!=-1)
           right=mem[k+1][j];
        else
        {
            right=solve(s,k+1,j,mem);
            mem[k+1][j]=right;
        }
        mem[i][j]=min(mem[i][j],1+left+right);
    }
    return mem[i][j];
}
int Solution::minCut(string A) 
{
    vector<vector<int>> mem(502,vector<int>(502,-1));
    int i=0;
    int j=A.length()-1;
    return solve(A,i,j,mem);
}

