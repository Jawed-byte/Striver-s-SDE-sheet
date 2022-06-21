// Recursive
    
    int solve(int arr[], int i, int j){
        if(i>=j)
          return 0;
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            mn = min(mn,temp);
        }
        return mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
      int i=1, j=N-1;
      return solve(arr,i,j);
    }
    
    */
    
// Memoization 
    
    int solve(int i,int j,int arr[],vector<vector<int>> &mem){
        if(i>=j) 
          return 0;
        else if(mem[i][j]!=-1) 
          return mem[i][j];
        int mn= INT_MAX;
        for(int k=i;k<j;k++){
          int ans=solve(i,k,arr,mem)+solve(k+1,j,arr,mem)+(arr[i-1]*arr[k]*arr[j]);
          mn = min(mn,ans);
        }
        return mem[i][j]=mn;
    }
    
    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>>mem(101,vector<int>(101,-1));
        return solve(1,N-1,arr,mem);
    }
