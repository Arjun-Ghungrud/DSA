class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=2;
        if(i>0 && grid[i-1][j]==1)dfs(i-1,j,grid);
        if(i<grid.size()-1 && grid[i+1][j]==1)dfs(i+1,j,grid);
        if(j>0 && grid[i][j-1]==1)dfs(i,j-1,grid);
        if(j<grid[0].size()-1 && grid[i][j+1]==1)dfs(i,j+1,grid);
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==1){
                dfs(i,m-1,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==1){
                dfs(n-1,i,grid);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(0,i,grid);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)count++;
            }
        }
        return count;
    }
};