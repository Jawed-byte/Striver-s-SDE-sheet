// Method1 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( matrix[i][j]==0){
                    for(int k=0;k<m;k++){
                        if(matrix[k][j]!=0)
                            matrix[k][j]=INT_MIN+1;
                    }
                    for(int k=0;k<n;k++){
                        if(matrix[i][k]!=0)
                            matrix[i][k]=INT_MIN+1;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==INT_MIN+1)
                    matrix[i][j]=0;
            }
        }
    }
};

// Method2

class Solution{
public:
    void setZeroes(vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> R(n,-1);
        vector<int> C(m,-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    R[j]=0;
                    C[i]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(R[j]==0 || C[i]==0)
                    matrix[i][j]=0;
            }
        }
    }
};

// Method3

class Solution{
public:
    void setZeroes(vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        int n0=1;
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0)
                n0=0;
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=matrix[0][j]=0;
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(n0==0)
                matrix[i][0]=0;
        }
    }
};
