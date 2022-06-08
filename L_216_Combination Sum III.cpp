class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, int start,int k, int target){
        if(target==0 && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<=9;i++){
            if(target<i)
                break;
            temp.push_back(i);
            backtrack(ans,temp,i+1,k,target-i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans,temp,1,k,target);
        return ans;
    }
};
