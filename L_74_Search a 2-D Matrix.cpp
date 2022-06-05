/* -------------- Brute Force ---------------------

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==target)
                    return true;
            }
        }
        return false;
    }
};

---------------------------------------------------*/

// Binary Search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.empty())
            return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j =  n-1;
        
        while (i < m && j >= 0) {
            if (matrix[i][j] > target) {
                j--;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
