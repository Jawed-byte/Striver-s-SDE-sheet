#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> A, int n, int q, vector<vector<int>> queries){
    int ans=0;
    for(int i=0;i<n;i++)
    ans+=A[i];
    for(int i=0;i<q;i++)
    ans+=queries[i][0]*(queries[i][2]-queries[i][1]+1);
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
        int q;
        cin>>q;
        vector<vector<int>> queries(q,vector<int>(3,0));
        for(int i=0;i<q;i++){
            int x,l,r;
            cin>>x>>l>>r;
            queries[i][0]=x;
            queries[i][1]=l;
            queries[i][2]=r;
        }
        int ans=fun(A,n,q,queries);
        cout<<ans<<"\n";
    }
}
