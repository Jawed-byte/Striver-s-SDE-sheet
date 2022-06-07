// Brute Force

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        int n=nums.size();
        if(n<3)
            return {};
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0)
                        s.insert({nums[i],nums[j],nums[k]});
                }
            }
        }
        vector<vector<int>> res(s.begin(),s.end());
        return res;
    }
};

// Hashing

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        set<set<int>> s;
        int n=nums.size();
        if(n<3)
            return {};
        sort(nums.begin(),nums.end());
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++)
            hash[nums[i]]++;
        for(int i=1;i<n;i++){
            hash[nums[i]]--;
            for(int j=i+1;j<n;j++){
                hash[nums[j]]--;
                int val=0-(nums[i]+nums[j]);
                if(hash.find(val)!=hash.end()){
                    s.insert({nums[i],nums[j],val});
                }
                hash[nums[j]]++;
            }
            hash[nums[i]]++;
        }
        vector<vector<int>>res;
        for(auto st: s)
            res.push_back({st});
        return res;
    }
};

// Binary search logic

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        if(nums.size()<3)
            return res;
        for(int i=0;i<nums.size()-1; i++)
        {
            int left=i+1;
            int right=nums.size()-1;
            int sum=0-nums[i];
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(left<right)
            {
                if(nums[left]+nums[right]==sum)
                {
                    vector<int>temp={nums[i],nums[left],nums[right]};
                    res.push_back(temp);
                    while(left<right && nums[left]==nums[left+1])
                        left++;
                    while(left<right && nums[right]==nums[right-1]) 
                        right--;
                    left++;
                    right--;
                }
                else if(nums[left]+nums[right]<sum)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};
