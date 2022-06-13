vector<int> Solution::prevSmaller(vector<int> &A) 
{
  vector<int>res;
  stack<int>s;
  int n=A.size();

  for(int i=0;i<n;i++)
  {
      if(s.empty())
         res.push_back(-1);
      if(!s.empty() && s.top()<A[i])
         res.push_back(s.top());
      if(!s.empty() && s.top()>=A[i])
      {
          while(!s.empty() && s.top()>=A[i])
          {
              s.pop();
          }
          if(s.empty())
             res.push_back(-1);
          else
             res.push_back(s.top());
      }
      s.push(A[i]);    
  }
  return res;
}
