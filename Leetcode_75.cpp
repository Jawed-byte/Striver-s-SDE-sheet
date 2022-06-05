/*class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int c0=0,c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                c0++;
            else if(nums[i]==1)
                c1++;
            else if(nums[i]==2)
                c2++;
        }
        nums.clear();
        while(c0--)
            nums.push_back(0);
        while(c1--)
            nums.push_back(1);
        while(c2--)
            nums.push_back(2);
    }
};*/

class Solution{
public:
    void sortColors(vector<int>& nums){
        int n=nums.size();
        int i=0,m=0,j=n-1;
        while(m<=j){
            if(nums[m]==0){
                swap(nums[i++],nums[m++]);
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[m],nums[j]);
                j--;
            }
        }
    }
};
