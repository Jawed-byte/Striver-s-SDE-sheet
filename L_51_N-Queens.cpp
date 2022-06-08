// ------------ Method 1-------------

class Solution {
public:
    bool isSafe(int row, int col, vector<string> board, int n){
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        col = dupcol;
        row = duprow;
        while(col>=0){
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        row = duprow;
        col = dupcol;
        while(row<n && col>=0){
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return ;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};


// Optimized -> Used hashing to check if the current position safe or not to place the queen.

class Solution{
public:
  void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag, int n){
      if(col==n){
          ans.push_back(board);
          return ;
      }
      for(int row=0;row<n;row++){
          if(leftRow[row]==0 && lowerDiag[row+col]==0 && upperDiag[n-1+col-row]==0){
              board[row][col]='Q';
              leftRow[row]=1;
              lowerDiag[row+col]=1;
              upperDiag[n-1+col-row]=1;
              solve(col+1,board,ans,leftRow,upperDiag,lowerDiag,n);
              board[row][col]='.';
              leftRow[row]=0;
              lowerDiag[row+col]=0;
              upperDiag[n-1+col-row]=0;
          }
      }
  }  
  vector<vector<string>> solveNQueens(int n){
      vector<vector<string>> ans;
      vector<string> board(n);
      string s(n,'.');
      for(int i=0;i<n;i++)
          board[i]=s;
      vector<int>leftRow(n,0), upperDiag(2*n-1,0), lowerDiag(2*n-1,0);
      solve(0,board,ans,leftRow,upperDiag,lowerDiag,n);
      return ans;
  }  
};
