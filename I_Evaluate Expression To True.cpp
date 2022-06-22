int mod = 1003;

/* Recursive

int solve(string s, int i, int j, int isTrue){
    if(i>j)
      return 0;
    if(i==j){
        if(isTrue)
          return s[i]=='T';
        else
          return s[i]=='F';
    }
    int ans = 0;
    for(int k=i+1;k<=j-1;k+=2){
        int lt = solve(s,i,k-1,1);
        int lf = solve(s,i,k-1,0);
        int rt = solve(s,k+1,j,1);
        int rf = solve(s,k+1,j,0);
        if(s[k] == '&'){
            if(isTrue)
             ans = (ans + lt*rt%mod) % mod;
            else
             ans = (ans + lf*rf%mod + lt*rf%mod + lf*rt%mod) % mod;
        }
        else if(s[k]== '|'){
            if(isTrue)
              ans = (ans + lt*rt%mod + lt*rf%mod + lf*rt%mod) % mod;
            else
              ans = (ans + lf*rf%mod) % mod;
        }
        else if(s[k]== '^'){
            if(isTrue)
              ans = (ans + lf*rt%mod + lt*rf%mod) % mod;
            else
              ans = (ans + lf*rf%mod + lt*rt%mod) % mod;
        }
    }
    return ans;
}
int Solution::cnttrue(string A) {
    int n=A.size();
    return solve(A,0,n-1,true);
}

 */
 
// Memoization

int solve(string s, int i, int j, int isTrue,vector<vector<vector<int>>> &mem){
    if(i>j)
      return 0;
    if(i==j){
        if(isTrue)
          return s[i]=='T';
        else
          return s[i]=='F';
    }
    if(mem[i][j][isTrue]!=-1)
     return mem[i][j][isTrue];
    int ans = 0;
    for(int k=i+1;k<=j-1;k+=2){
        int lt = solve(s,i,k-1,1,mem);
        int lf = solve(s,i,k-1,0,mem);
        int rt = solve(s,k+1,j,1,mem);
        int rf = solve(s,k+1,j,0,mem);
        if(s[k] == '&'){
            if(isTrue)
             ans = (ans + lt*rt%mod) % mod;
            else
             ans = (ans + lf*rf%mod + lt*rf%mod + lf*rt%mod) % mod;
        }
        else if(s[k]== '|'){
            if(isTrue)
              ans = (ans + lt*rt%mod + lt*rf%mod + lf*rt%mod) % mod;
            else
              ans = (ans + lf*rf%mod) % mod;
        }
        else if(s[k]== '^'){
            if(isTrue)
              ans = (ans + lf*rt%mod + lt*rf%mod) % mod;
            else
              ans = (ans + lf*rf%mod + lt*rt%mod) % mod;
        }
    }
    return mem[i][j][isTrue] = ans;
}
int Solution::cnttrue(string A) {
    int n=A.size();
    vector<vector<vector<int>>> mem(151,vector<vector<int>>(151,vector<int>(2,-1)));
    return solve(A,0,n-1,true,mem);
}
