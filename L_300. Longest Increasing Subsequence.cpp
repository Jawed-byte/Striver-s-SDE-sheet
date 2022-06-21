/* Recursive

class Solution {
public:
    int solve(vector<int>&nums, int prev_idx, int curr_idx){
        int n=nums.size();
        if(curr_idx==n)
            return 0;
        int op1 = 0;
        if(prev_idx==-1 || nums[curr_idx] > nums[prev_idx])
            op1 =  1 + solve(nums,curr_idx,curr_idx+1);
        int op2 = solve(nums,prev_idx,curr_idx+1);
        return max(op1,op2);
    }
    int lengthOfLIS(vector<int>& nums){
        return solve(nums,-1,0);
    }   
};
        
*/

/* Memoization

class Solution {
public:
    int solve(vector<int>&nums, int prev_idx, int curr_idx, vector<vector<int>> &mem){
        int n=nums.size();
        if(curr_idx==n)
            return 0;
        int op1 = 0;
        if(prev_idx!=-1 && mem[prev_idx][curr_idx]!=-1)
            return mem[prev_idx][curr_idx];
        if(prev_idx==-1 || nums[curr_idx] > nums[prev_idx])
            op1 =  1 + solve(nums,curr_idx,curr_idx+1,mem);       
        int op2 = solve(nums,prev_idx,curr_idx+1,mem);
        if(prev_idx!=-1)
            mem[prev_idx][curr_idx]=max(op1,op2);
        return max(op1, op2);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> mem(2501,vector<int>(2501,-1));
        return solve(nums, -1, 0,mem);
    }
};

*/

/* Tabulation dp

class Solution{
public:
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        int lis[n];
        lis[0]=1;
        for(int i=1;i<n;i++)
        {
         lis[i]=1;
         for(int j=0;j<i;j++)
         if(nums[i]>nums[j] && lis[i]<lis[j]+1)
         lis[i]=lis[j]+1;
        }
        return *max_element(lis,lis+n);
    }
};

*/

// Binary search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(lis.back()<nums[i])
                lis.push_back(nums[i]);
            else{
                int idx=lower_bound(lis.begin(), lis.end(), nums[i])-lis.begin();
                lis[idx]=nums[i];
            }
        }
        return lis.size();
    }
};
