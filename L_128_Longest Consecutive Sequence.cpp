/* 

class Solution {
public:
    bool isArrayContains(vector<int>& nums, int num){
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==num){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int ls=0;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int cs=1;
            while(isArrayContains(nums,num+1)){
                num+=1;
                cs+=1;
            }
            ls=max(ls,cs);
        }
        return ls;
    }
};*/

/* Time & Space Complexity Analysis.
0(n) [for first loop] * 0(n) [while loop, everytime we are passing the function array contains num+1 to check if it exists or not] * 0(n) [isArrayContains function take 0(n) to perform a linear scan. So, total TC = 0(n^3)
SC:0(1)
*/


/* Sorting Solution ------------------------

class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        int n=nums.size();
        if(n==0)
            return 0;
        int ls=0,cs=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]==nums[i-1]+1)
                    cs+=1;
                else{
                    ls=max(ls,cs);
                    cs=1;
                }
            }
         }
         return max(ls,cs);
    }
};

---------------------------------------------------*/


// Solution using unordered set.

class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        int n=nums.size();
        if(n==0)
            return 0;
        int ls=0,cs=1;
        unordered_set<int>s;
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        for(int num: nums){
            if(!s.count(num-1)){
                int currentnum=num;
                cs=1;
                while(s.count(currentnum+1)){
                    currentnum+=1;
                    cs+=1;
                }
                ls=max(ls,cs);
            }
        }
        return ls;
    }
};
