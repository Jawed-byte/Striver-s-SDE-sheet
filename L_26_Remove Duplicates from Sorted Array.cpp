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

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=1, r=1;
        while(r<n){
            if(nums[r]!=nums[r-1]){
                nums[l]=nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};
