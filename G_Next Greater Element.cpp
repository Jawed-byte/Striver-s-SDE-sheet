vector<long long>nextLargerElement(long long arr[], int n)
{
  vector<long long>res;
  stack<long long>s;
  
  for(int i=n-1;i>=0;i--)
  {
      if(s.empty())
         res.push_back(-1);
      if(!s.empty() && s.top()>arr[i])
         res.push_back(s.top());
      if(!s.empty() && s.top()<=arr[i])
      {
          while(!s.empty() && s.top()<=arr[i])
          {
              s.pop();
          }
          if(s.empty())
             res.push_back(-1);
          else
             res.push_back(s.top());
      }
      s.push(arr[i]);    
  }
  reverse(res.begin(),res.end());
  return res;
}
