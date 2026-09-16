class Solution {
public:
    long long helper(int n,int k,vector<vector<int>>&dp){
        if(k==0)return 1;
        if(n<k)return 0;
        if(dp[n][k]!=-1)return dp[n][k];
        return dp[n][k]=(helper(n-1,k-1,dp)+helper(n-1,k,dp))%1000000007;
    }
    int numberOfSets(int n, int k){
        int N=n+k-1;
        int K=2*k;
        vector<vector<int>>dp(N+1,vector<int>(K+1,-1));
        return helper(N,K,dp);
    }
};