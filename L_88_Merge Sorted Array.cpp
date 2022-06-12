// Method1: O(nlogn) with extra space 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int> nums(n+m);
        while(i<m && j<n){
            if(nums1[i]<nums2[j])
                nums[k++]=nums1[i++];
            else
                nums[k++]=nums2[j++];
        }
        while(i<m)
            nums[k++]=nums1[i++];
        while(j<n)
            nums[k++]=nums2[j++];
        for(int i=0;i<n+m;i++)
            nums1[i]=nums[i];
    }
};


// Method2: O(nlogn) without extra space 

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i,j,k,hole;
        for(i=0,j=0; i<m && j<n;j++){
            k=i;
            while(k<m && nums1[k]<nums2[j])
                k++;
            hole=m;
            while(hole!=k){
                nums1[hole]=nums1[hole-1];
                hole--;
            }
            nums1[hole]=nums2[j];
            i=hole;
            m++;
        }
        for(i=m;j<n;j++){
            nums1[i]=nums2[j];
            i++;
        }
    }
};

// Method3: Another no extra space solution 

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j])
                nums1[k--]=nums1[i--];
            else
                nums1[k--]=nums2[j--];
        }
        while(i>=0)
            nums1[k--]=nums1[i--];
        while(j>=0)
            nums1[k--]=nums2[j--];
    }
};

// Method4: Gap Method 

class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i=0,j=0;
        for(int i=m;i<m+n;i++,j++)
            nums1[i]=nums2[j];
        int gap=ceil((m+n)/2);
        while(gap>=1){
            i=0,j=i+gap;
            while(j<m+n){
                if(nums1[i]>nums1[j])
                    swap(nums1[i],nums1[j]);
                i++;
                j++;
            }
            if(gap==1)
                break;
            gap=(gap+1)/2;
        }
    }
};
