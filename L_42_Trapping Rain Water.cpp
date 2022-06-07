// Method1

class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        int mxl[n];
        int mxr[n];
        mxl[0]=height[0];
        for(int i=1;i<n;i++)
            mxl[i]=max(mxl[i-1],height[i]);
        mxr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
            mxr[i]=max(mxr[i+1],height[i]);
        
        int water[n];
        for(int i=0;i<n;i++)
        {
            if(mxl[i]<mxr[i])
                water[i]=mxl[i]-height[i];
            else
                water[i]=mxr[i]-height[i];
        }
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=water[i];
        return sum;
    }
};


// Method2

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int maxleft=0, maxright=0;
        int res=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(maxleft<height[left])
                    maxleft=height[left];
                else
                    res+=maxleft-height[left];
                left++;
            }
            else{
                if(maxright<height[right])
                    maxright=height[right];
                else
                    res+=maxright-height[right];
                right--;
            }
        }
        return res;
    }
};
