class Solution {
public:
    bool helper(int i,int j,vector<vector<char>>& grid,int count,vector<vector<vector<int>>>&dp){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || count<0)return false;
        if(grid[i][j]=='(')count+=1;
        else if(grid[i][j]==')')count-=1;
        if(count < 0)return false;
        if(i==grid.size()-1 && j==grid[0].size()-1 && count==0)return true;
        if(dp[i][j][count]!=-1)return dp[i][j][count];
        bool a=helper(i+1,j,grid,count,dp);
        bool b=helper(i,j+1,grid,count,dp);
        return dp[i][j][count]=a || b;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+n+1,-1)));
        return helper(0,0,grid,count,dp);
    }
};