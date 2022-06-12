class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        priority_queue<pair<int,pair<int,int>>>maxh;
        for(int i=0;i<points.size();i++)
        {
            maxh.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(maxh.size()>k)
                maxh.pop();
        }
        while(maxh.size()>0)
        {
            pair<int,int>p=maxh.top().second;
            vector<int>v;
            v.push_back(p.first);
            v.push_back(p.second);
            maxh.pop();
            res.push_back(v);
        }
        return res;
    }
};
