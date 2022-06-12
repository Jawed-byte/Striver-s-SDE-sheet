class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int i=0;
        int j=letters.size()-1;
        char res=letters[i];
        while(i<=j)
        {
            int m=i+(j-i)/2;
            if(letters[m]==target)
                i=m+1;
            else if(letters[m]<target)
                i=m+1;
            else
            {
                res=letters[m];
                j=m-1;
            }
        }
        return res;
    }
};
