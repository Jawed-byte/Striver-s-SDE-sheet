vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(),mcount = n/3,c1=0,c2=0,n1=-1,n2=-1;
        vector<int> res;
        
        for(int i=0;i<n;i++){
             if(nums[i] == n1){
                 c1++;
             }else if(nums[i]==n2){
                 c2++;
             }else if(c1==0){
                 n1 = nums[i];
                 c1++;
             }else if(c2==0){
                 n2 = nums[i];
                 c2++;
             }else{
                 c1--;
                 c2--;
            }            
        }
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==n1){
                c1++;
            }
            else if(nums[i]==n2){
                c2++;
            }
        }
        if(c1 > mcount){
            res.push_back(n1);
        }
        if(c2 > mcount){
            res.push_back(n2);
        }
     return res;
   }
