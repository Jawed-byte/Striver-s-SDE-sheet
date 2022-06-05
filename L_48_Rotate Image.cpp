/* --------- O(n^2) time & O(n^2) space ------------

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n-i-1]=matrix[i][j];
            }
        }
        matrix=ans;
    }
};

---------------------------------------------------*/

/* --------- O(n^2) Solution with no extra space ---------------

class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};

-----------------------------------------------------------------*/
