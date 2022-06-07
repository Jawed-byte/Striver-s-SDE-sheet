int findPlatform(int arr[], int dep[], int n)
    {
      sort(arr,arr+n);
      sort(dep,dep+n);
      int plat_needed=1, res=1;
      int i=1,j=0;
      while(i<n && j<n){
          if(arr[i]<=dep[j]){
              plat_needed++;
              i++;
          }
          else if(arr[i]>dep[j]){
              plat_needed--;
              j++;
          }
          res = max(res,plat_needed);
      }
      return res;
    }
