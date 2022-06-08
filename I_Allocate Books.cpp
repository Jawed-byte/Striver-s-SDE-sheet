int isPossible(vector<int> &A, int pages, int students){
    int cnt = 0;
    int sumAllocated = 0;
    for(int i=0;i<A.size();i++){
        if(sumAllocated+A[i]>pages){
            cnt++;
            sumAllocated = A[i];
            if(sumAllocated > pages)
             return false;
        }
        else
          sumAllocated += A[i];
    }
    if(cnt < students)
     return true;
    else
     return false;
}

int Solution::books(vector<int> &A, int B) {
    if(B > A.size())
     return -1;
    int sum=0;
    for(int i=0;i<A.size();i++)
    sum+=A[i];
    int l=A[0], h=sum;
    while(l<=h){
        int mid = l+(h-l)/2;
        if(isPossible(A,mid,B))
          h = mid-1;
        else
          l = mid+1;
    }
return l;    
}
