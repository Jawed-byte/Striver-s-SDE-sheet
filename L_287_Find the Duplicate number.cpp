// Method1: O(nlogn) Sorting Solution 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};

// Method2: Hashing Solution

class Solution{
public:
    int findDuplicate(vector<int>& nums){
        int n=nums.size();
        vector<int> hash(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(hash[nums[i]]==1){
                ans=nums[i];
                break;
            }
            hash[nums[i]]++;
        }
        return ans;
    }
};

// Method3: LinkedList Cycle method

class Solution{
public:
    int findDuplicate(vector<int>& nums){
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
