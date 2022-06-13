void span(int arr[], int n)
{
    stack<pair<int,int>>s;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
     if(s.empty())
        res.push_back(-1);
     if(!s.empty() && s.top().first>arr[i])
        res.push_back(s.top().second);
     if(!s.empty() && s.top().first<=arr[i])
     {
         while(!s.empty() && s.top().first<=arr[i])
         {
             s.pop();
         }
         if(s.empty())
           res.push_back(-1);
         else
           res.push_back(s.top().second);
     }
     s.push({arr[i],i});
    }
    for(int i=0;i<res.size();i++)
    res[i]=i-res[i];
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
}
