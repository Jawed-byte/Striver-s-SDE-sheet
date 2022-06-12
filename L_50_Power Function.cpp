// Method1: Brute Force

class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0)
            return 1;
        else if(n>0) 
            return x*myPow(x,n-1); 
        else
            return (1/x)*myPow(x,n+1); 
    }
};

// Method2: Binary Exponentiation

class Solution {
public:
    double myPow(double x, int n) {
        
       double ans= 1.0;
       long long nn =n;
        
       if(nn<0) nn=-1*nn;
        
       while(nn){
           
           if(nn % 2){
               ans=ans*x;
               nn--;
           }else{
               x=x*x;
               nn=nn/2;
           }
       }
        if(n<0)ans =(double)1.0/(double)ans;
        return ans;
    }
};
