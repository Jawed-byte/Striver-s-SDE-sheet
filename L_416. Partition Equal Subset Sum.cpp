/* Recursive

class Solution {
public:
    int knapSack(vector<int> &A, int B, int n){
       if(n==0)
         return B==0;
       if(B==0)
         return 1;
       if(A[n-1]==B)
         return 1;
       else if(A[n-1]<B)
         return knapSack(A,B-A[n-1],n-1) ||   knapSack(A,B,n-1);
       else
         return knapSack(A,B,n-1);
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        else
            return knapSack(nums, sum/2, n);
    }
};

*/

/* Memoization

class Solution{
public:
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
    bool canPartition(vector<int> &nums){
        vector<vector<int>> mem(201,vector<int>(20001,-1));
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        else
            return knapSack(nums, sum/2, n, mem);
    }
};

*/

// Tabulation dp

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        sum/=2;
        bool dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
            dp[i][0]=true;
        for(int j=1;j<sum+1;j++)
            dp[0][j]=false;
        for(int i=1;i<n+1;i++)
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        return dp[n][sum];
    }
};
