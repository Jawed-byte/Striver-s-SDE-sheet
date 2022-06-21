class Solution {
public:
    int subsetSum(vector<int>nums,int n,int sum1){
        int dp[n+1][sum1+1];
        for(int i=0;i<n+1;i++)
            dp[i][0]=1;
        for(int j=1;j<sum1+1;j++)
            dp[0][j]=0;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum1+1;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum1];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum<abs(target) || (sum+target)%2!=0)
            return 0;
        int s=(sum+target)/2;
        return subsetSum(nums,nums.size(),s);   
    }
};
