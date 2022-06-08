class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(vector<vector<string>> &ans,vector<string> &temp, string &s, int start){
        if(start==s.size())
            ans.push_back(temp);
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                backtrack(ans,temp,s,i+1);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        backtrack(ans,temp,s,0);
        return ans;
    }
};
