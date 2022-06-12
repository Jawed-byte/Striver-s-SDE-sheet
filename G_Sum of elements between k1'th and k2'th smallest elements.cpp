class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(int i=0;i<N;i++)
        minHeap.push(A[i]);
        
        int firstK1=K1;
        while(!minHeap.empty() && firstK1>0){
            minHeap.pop();
            firstK1--;
        }
        long long sum=0;
        int count=K2-K1-1;
        while(!minHeap.empty() && count>0){
            sum+=minHeap.top();
            minHeap.pop();
            count--;
        }
        return sum;
    }
};
