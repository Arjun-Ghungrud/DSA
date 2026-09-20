class Solution {
public:
    int helper(int egg,int n,vector<vector<int>>&dp){
        if(n==0 || n==1)return n;
        if(egg==1)return n;
        if(dp[egg][n]!=-1)return dp[egg][n];
        int minans=INT_MAX;
        for(int i=1;i<=n;i++){
            int breaks=helper(egg-1,i-1,dp);
            int notBreaks=helper(egg,n-i,dp);
            int val=1+max(breaks,notBreaks);
            minans=min(minans,val);
        }
        return dp[egg][n]= minans;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        return helper(2,n,dp);
    }
};