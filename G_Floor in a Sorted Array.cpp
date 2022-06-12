class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x)
    {
     int i=0;
     int j=n-1;
     int res=-1;
     while(i<=j)
     {
         int m=i+(j-i)/2;
         if(v[m]==x)
         {
             res=m;
             break;
         }
         else if(v[m]<x)
         {
             res=m;
             i=m+1;
         }
         else
         {
             j=m-1;
         }
     }
     return res;
    }
};
