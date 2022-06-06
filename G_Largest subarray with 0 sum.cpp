// Brute Force

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
      int max_len=0; 
      for (int i=0;i<n;i++){
      int curr_sum=0;
      for(int j=i;j<n;j++){
            curr_sum+=nums[j];
            if(curr_sum==0)
                max_len=max(max_len,j-i+1);
        }
    }
    return max_len;
    }
};

// Using unordered map

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> mp;
        int maxi = 0;
        int sum = 0;
        for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0)
          maxi = i+1;
        else{
          if(mp.find(sum)!=mp.end())
              maxi = max(maxi,i-mp[sum]);
          else
              mp[sum]=i;
         }
        }
        return maxi;
    }
};
