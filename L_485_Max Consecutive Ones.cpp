class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                mx=max(mx,cnt);
            }
            else
                cnt=0;
        }
        return mx;
    }
};
