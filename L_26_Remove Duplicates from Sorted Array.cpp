// Hashing 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        map<int,int>mp;
        int n=nums.size();
        int i=0;
        while(i<n){
            if(mp.find(nums[i])==mp.end()){
                cnt++;
            }
            mp[nums[i]]++;
            i++;
        }
        nums.clear();
        for(auto it: mp)
            nums.push_back(it.first);
        return cnt;
    }
};

// optimized

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size()==0)
            return 0;
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
