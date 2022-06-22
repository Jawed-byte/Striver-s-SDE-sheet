/* Recursive 

int Solution::solve(int e, int f) {
    if(f==0 || f==1)
      return f;
    if(e==1)
      return f;
    int mn = INT_MAX;
    for(int k=1;k<=f;k++){
        int temp = 1+max(solve(e-1,k-1),solve(e,f-k));
        mn = min(mn,temp);
    }
    return mn;
}

*/

/* Memoization

int helper(int e, int f, vector<vector<int>> &mem){
    if(f==0 || f==1)
      return f;
    if(e==1)
      return f;
    if(mem[e][f]!=-1)
      return mem[e][f];
    int mn = INT_MAX;
    for(int k=1;k<=f;k++){
        int temp = 1+max(helper(e-1,k-1,mem),helper(e,f-k,mem));
        mn = min(mn,temp);
    }
    return mem[e][f] = mn;
}
int Solution::solve(int A, int B) {
    vector<vector<int>> mem(101,vector<int>(10001,-1));
    return helper(A,B,mem);
}

*/

int helper(int e, int f, vector<vector<int>> &mem){
    if(f==0 || f==1)
      return f;
    if(e==1)
      return f;
    if(mem[e][f]!=-1)
      return mem[e][f];
    int mn = INT_MAX;
    for(int k=1;k<=f;k++){
        int low=0, high=0;
        if(mem[e-1][k-1]!=-1)
         low = mem[e-1][k-1];
        else
         low = helper(e-1,k-1,mem);
         mem[e-1][k-1] = low;
        if(mem[e][f-k]!=-1)
         high = mem[e][f-k];
        else
         high = helper(e, f-k,mem);
         mem[e][f-k] = high;
        int temp = 1+max(low,high);
        mn = min(mn,temp);
    }
    return mem[e][f] = mn;
}
int Solution::solve(int A, int B) {
    vector<vector<int>> mem(101,vector<int>(10001,-1));
    return helper(A,B,mem);
}
