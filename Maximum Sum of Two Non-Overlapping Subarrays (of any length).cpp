#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> A, int n){
    vector<int> forward;
    vector<int> backward(n);
    int sum=0, mx=0;
    forward.push_back(0);
    backward.push_back(0);
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum > mx) mx=sum;
        if(sum < 0) sum=0;
        forward.push_back(mx);
    }
    sum=0, mx=0;
    for(int i=n-1;i>=0;i--){
        sum+=A[i];
        if(sum > mx) mx=sum;
        if(sum < 0) sum=0;
        backward[i] = mx;
    }
    int ans=0;
    for(int i=0;i<=n;i++)
    ans=max(ans,forward[i]+backward[i]);
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for(int i=0;i<n;i++)
        cin>>A[i];
        cout<<solve(A,n)<<"\n";
    }
    return 0;
}
