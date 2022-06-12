vector<int> Solution::solve(vector<int> &A, int B) 
{
    priority_queue<int,vector<int>,greater<int>>minh;
    vector<int>res;
    for(int i=0;i<A.size();i++)
    {
        minh.push(A[i]);
        if(minh.size()>B)
            minh.pop();
    }
    while(minh.size()>0)
    {
     res.push_back(minh.top());
     minh.pop();
    }
    return res;
}
