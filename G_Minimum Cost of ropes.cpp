long long minCost(long long arr[], long long n) {
    priority_queue<long long,vector<long long>,greater<long long>>minh;
    for(int i=0;i<n;i++)
    minh.push(arr[i]);
    
    long long cost=0;
    while(minh.size()>=2)
    {
        long long first=minh.top();
        minh.pop();
        long long second=minh.top();
        minh.pop();
        cost+=first+second;
        minh.push(first+second);
    }
    
    return cost;
}
