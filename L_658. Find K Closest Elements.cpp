
class Solution {
public:
    vector<int> findClosestElements(vector<int>& A, int k, int x) {
       int l=0,r=A.size()-k;
       while(l<r)
       {
           int m=l+(r-l)/2;
           if(x-A[m]>A[m+k]-x)
               l=m+1;
           else
               r=m;
       }
     return vector<int>(A.begin()+l,A.begin()+l+k);
    }
};
