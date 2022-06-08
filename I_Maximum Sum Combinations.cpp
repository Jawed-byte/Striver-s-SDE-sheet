// Brute Force

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    vector<int> res;
    int n=A.size();
    priority_queue<int> maxh;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maxh.push(A[i]+B[j]);
        }
    }
    int cnt=0;
    while(cnt<C){
      res.push_back(maxh.top());
      maxh.pop();
      cnt++;
    }
    return res;
}

// Optimized

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C){
    vector<int> res;
    int n=A.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int, pair<int,int>>> maxh;
    set<pair<int,int>> s;
    maxh.push({A[n-1]+B[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});
    for(int cnt=0;cnt<C;cnt++){
        pair<int,pair<int,int>> temp = maxh.top();
        maxh.pop();
        res.push_back(temp.first);
        int i=temp.second.first;
        int j=temp.second.second;
        if(s.find({i-1,j})==s.end()){
            maxh.push({A[i-1]+B[j],{i-1,j}});
            s.insert({i-1,j});
        }
        if(s.find({i,j-1})==s.end()){
            maxh.push({A[i]+B[j-1],{i,j-1}});
            s.insert({i,j-1});
        }
    }
    return res;
}
