int Solution::largestRectangleArea(vector<int> &A) 
{
 vector<long long>left;  //to store next smallest to left
 stack<pair<long long,long long>>s;
 long long n=A.size();
 if(n==1)
   return A[0];
 for(long long i=0;i<n;i++)
 {
     if(s.empty())
     {
         left.push_back(-1);
     }
     if(!s.empty() && s.top().first<A[i])
     {
         left.push_back(s.top().second);
     }
     if(!s.empty() && s.top().first>=A[i])
     {
         while(!s.empty() && s.top().first>=A[i])
         {
             s.pop();
         }
         if(s.empty())
             left.push_back(-1);
         else
             left.push_back(s.top().second);
     }
     s.push({A[i],i});
 }
 
 vector<long long>right;   //To store next smallest to right
 stack<pair<long long,long long>>s2;
 for(int i=n-1;i>=0;i--)
 {
     if(s2.empty())
       right.push_back(-1);
     if(!s2.empty() && s2.top().first < A[i])
       right.push_back(s2.top().second);
     if(!s2.empty() && s2.top().first>=A[i])
     {
         while(!s2.empty() && s2.top().first>=A[i])
         {
             s2.pop();
         }
         if(s2.empty())
            right.push_back(-1);
         else
            right.push_back(s2.top().second);
     }
     s2.push({A[i],i});
 }
 reverse(right.begin(),right.end());
 vector<long long>width(n),area(n);
 for(long long i=0;i<n;i++)
 {
     if(right[i]==-1)
       right[i]=n;
     width[i]=right[i]-left[i]-1;
 }
 for(long long i=0;i<n;i++)
 area[i]=A[i]*width[i];
 long long ans=1;
 for(long long i=0;i<n;i++)
 ans=max(ans,area[i]);
 return ans;
}
