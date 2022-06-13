int Solution::largestRectangleArea(vector<int> &A) 
{
 vector<long long>left;  //to store next smallest to left
 stack<pair<long long,long long>>s;
 long long n=A.size();
 if(n==1)
   return A[0];
 for(long long i=0;i<n;i++)
 {
     if(s.empty())
     {
         left.push_back(-1);
     }
     if(!s.empty() && s.top().first<A[i])
     {
         left.push_back(s.top().second);
     }
     if(!s.empty() && s.top().first>=A[i])
     {
         while(!s.empty() && s.top().first>=A[i])
         {
             s.pop();
         }
         if(s.empty())
             left.push_back(-1);
         else
             left.push_back(s.top().second);
     }
     s.push({A[i],i});
 }
 
 vector<long long>right;   //To store next smallest to right
 stack<pair<long long,long long>>s2;
 for(int i=n-1;i>=0;i--)
 {
     if(s2.empty())
       right.push_back(-1);
     if(!s2.empty() && s2.top().first < A[i])
       right.push_back(s2.top().second);
     if(!s2.empty() && s2.top().first>=A[i])
     {
         while(!s2.empty() && s2.top().first>=A[i])
         {
             s2.pop();
         }
         if(s2.empty())
            right.push_back(-1);
         else
            right.push_back(s2.top().second);
     }
     s2.push({A[i],i});
 }
 reverse(right.begin(),right.end());
 vector<long long>width(n),area(n);
 for(long long i=0;i<n;i++)
 {
     if(right[i]==-1)
       right[i]=n;
     width[i]=right[i]-left[i]-1;
 }
 for(long long i=0;i<n;i++)
 area[i]=A[i]*width[i];
 long long ans=1;
 for(long long i=0;i<n;i++)
 ans=max(ans,area[i]);
 return ans;
}


// Method2

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int leftSmall[n], rightSmall[n];
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty())
                rightSmall[i]=n-1;
            else
                rightSmall[i]=st.top()-1;
            st.push(i);
        }
        int maxA=0;
        for(int i=0;i<n;i++){
            maxA = max(maxA,heights[i]*(rightSmall[i]-leftSmall[i]+1));
        }
        return maxA;
    }
};

// Method3

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int h = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width = i;
                else
                    width = i-st.top()-1;
                maxA = max(maxA,width*h);
            }
            st.push(i);
        }
        return maxA;
    }
};

