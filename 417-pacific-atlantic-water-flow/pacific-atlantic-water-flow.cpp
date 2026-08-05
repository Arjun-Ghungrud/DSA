class Solution {
public:
    
    void atlantic(int i,int j,vector<vector<int>>& mat,vector<vector<bool>>& vis){
        int n=mat.size();
        int m=mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(vis[i][j]) return;
        vis[i][j]=true;
        if(i>0 && mat[i-1][j]>=mat[i][j]){
            atlantic(i-1,j,mat,vis);
        }
        if(i<n-1 && mat[i+1][j]>=mat[i][j]){
            atlantic(i+1,j,mat,vis);
        }
        if(j>0 && mat[i][j-1]>=mat[i][j]){
            atlantic(i,j-1,mat,vis);
        }
        if(j<m-1 && mat[i][j+1]>=mat[i][j]){
            atlantic(i,j+1,mat,vis);
        }
    }
    void pacific(int i,int j,vector<vector<int>>& mat,vector<vector<bool>>& vis){
        int n=mat.size();
        int m=mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m)return;
        if(vis[i][j])return;
        vis[i][j]=true;
        if(i>0 && mat[i-1][j]>=mat[i][j]){
            pacific(i-1,j,mat,vis);
        }
        if(i<n-1 && mat[i+1][j]>=mat[i][j]){
            pacific(i+1,j,mat,vis);
        }
        if(j>0 && mat[i][j-1]>=mat[i][j]){
            pacific(i,j-1,mat,vis);
        }
        if(j<m-1 && mat[i][j+1]>=mat[i][j]){
            pacific(i,j+1,mat,vis);
        }
        return ;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>> vis1(n, vector<bool>(m, false));
        vector<vector<bool>> vis2(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            pacific(i,0,mat,vis1);
            atlantic(i,m-1,mat,vis2);
        }
        for(int i=0;i<m;i++){
            pacific(0,i,mat,vis1);
            atlantic(n-1,i,mat,vis2);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j] && vis2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};