class Solution {
public:
    int bfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>vis){
        queue<pair<int,int>>q;
        q.push({r,c});
        vis[r][c]=true;
        int ans=0;
        while(q.size()>0){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            ans+=1;
            if(i>0 && vis[i-1][j]==false && grid[i-1][j]==1){
                q.push({i-1,j});
                vis[i-1][j]=true;
            }
            if(i<grid.size()-1 && vis[i+1][j]==false && grid[i+1][j]==1){
                q.push({i+1,j});
                vis[i+1][j]=true;
            }
            if(j>0 && vis[i][j-1]==false && grid[i][j-1]==1){
                q.push({i,j-1});
                vis[i][j-1]=true;
            }
            if(j<grid[0].size()-1 && vis[i][j+1]==false && grid[i][j+1]==1){
                q.push({i,j+1});
                vis[i][j+1]=true;
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    int val=bfs(i,j,grid,vis);
                    ans=max(ans,val);
                }
            }
        }
        return ans;
    }
};