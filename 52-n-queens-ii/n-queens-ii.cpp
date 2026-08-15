class Solution {
public:
    bool issafe(vector<string>&board,int n,int row,int col){
        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q')return false;
        }
        //digonal left
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        //digonal right
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }
    void Nqueenconfi(vector<string>&board,int &ans,int n,int row){
        if(row==n){
            ans++;
            return ;
        }
        for(int j=0;j<n;j++){
            if(issafe(board,n,row,j)){
                board[row][j]='Q';
                Nqueenconfi(board,ans,n,row+1);
                board[row][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int ans=0;
        Nqueenconfi(board,ans,n,0);
        return ans;
    }
};