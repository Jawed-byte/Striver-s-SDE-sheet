/* --------------- Brute Force ----------------------- 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};

------------------------------------------------------*/

/* -------------- hashing Sol1 ----------------

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> res;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        for(int i=0;i<nums.size();i++){
            if(target-nums[i]==nums[i]){
                if(mp[nums[i]].size()>1){
                    res.push_back(mp[nums[i]][0]);
                    res.push_back(mp[nums[i]][1]);
                    break;
                }
            }
            else{
                if(mp[target-nums[i]].size()>0){
                    res.push_back(mp[nums[i]][0]);
                    res.push_back(mp[target-nums[i]][0]);
                    break;
                }
            }
        }
        return res;
    }
};

---------------------------------------------------*/

//* ------------ hashing Sol2 ------------------------

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> res;
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                res.push_back(i);
                res.push_back(mp[target-nums[i]]);
                break;
            }
            mp[nums[i]]=i;
        }
        return res;
    }
};

//-------------------------------------------------------*
