// Method1

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1)
            return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            for(int j=i+1;j<n;j++){
                int c=intervals[j][0];
                int d=intervals[j][1];
                if(b>=c){
                    b=max(b,d);
                    i=j;
                }
            }
            res.push_back({a,b});
        }
        return res;
    }
};

// Method2

class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        int n=intervals.size();
        if(n<=1)
            return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int i=1;
        res.push_back(intervals[0]);
        while(i<intervals.size()){
            vector<int>& temp=res.back();
            if(temp[1]<intervals[i][0])
                res.push_back(intervals[i]);
            else
                temp[1]=max(temp[1],intervals[i][1]);
            i++;
        }
        return  res;
    }
};
