class Solution {
public:
    bool helper(int i,int j,vector<vector<char>>& board, string word,int idx){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())return false;
        if(word[idx]!=board[i][j])return false;
        if(idx==word.size()-1)return true;
        char temp=board[i][j];
        board[i][j]='#';
        if(i>0 && helper(i-1,j,board,word,idx+1)){
            return true;
        }
        else if(i<board.size()-1 && helper(i+1,j,board,word,idx+1)){
            return true;
        }
        else if(j>0 && helper(i,j-1,board,word,idx+1)){
            return true;
        }
        else if(j<board[0].size()-1 && helper(i,j+1,board,word,idx+1)){
            return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(helper(i,j,board,word,0)==true)return true;
            }
        }
        return false;
    }
};