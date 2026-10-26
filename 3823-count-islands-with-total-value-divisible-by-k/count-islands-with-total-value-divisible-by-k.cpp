class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis,long long &sum){
        vis[i][j]=true;
        sum+=grid[i][j];
        if(i>0 && !vis[i-1][j] && grid[i-1][j]!=0)dfs(i-1,j,grid,vis,sum);
        if(i<grid.size()-1 && !vis[i+1][j] && grid[i+1][j]!=0)dfs(i+1,j,grid,vis,sum);
        if(j>0 && !vis[i][j-1] && grid[i][j-1]!=0)dfs(i,j-1,grid,vis,sum);
        if(j<grid[0].size()-1 && !vis[i][j+1] && grid[i][j+1]!=0)dfs(i,j+1,grid,vis,sum);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]!=0){
                    long long sum=0;
                    dfs(i,j,grid,vis,sum);
                    if(sum%k==0)count++;
                }
            }
        }
        return count;
    }
};