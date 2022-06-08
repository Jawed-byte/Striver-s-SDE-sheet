// ----- O(n) by taking xor of all the elements

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++)
            res=res^nums[i];
        return res;
    }
};

// Using Binary search

class Solution{
public:
    int singleNonDuplicate(vector<int>& nums){
        int l=0, h=nums.size()-2;
        while(l<=h){
            int mid = (l+h)>>1;
            if(nums[mid]==nums[mid^1])
                l = mid+1;
            else
                h = mid-1;
        }
        return nums[l];
    }
};
