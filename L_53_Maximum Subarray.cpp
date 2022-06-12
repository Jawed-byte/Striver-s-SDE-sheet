// Method1: O(n^3)

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
    }
};

// Method2: O(n^2)

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};

// Method3: O(n):

class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int n=nums.size();
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum);
            sum=max(sum,0);
        }
        return ans;
    }
};
