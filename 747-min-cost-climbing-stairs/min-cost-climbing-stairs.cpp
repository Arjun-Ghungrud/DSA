class Solution {
public:
    int helper(int idx,vector<int>& cost,vector<int>&dp){
        if(idx>=cost.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int s1=cost[idx]+helper(idx+1,cost,dp);
        int s2=cost[idx]+helper(idx+2,cost,dp);
        return dp[idx]=min(s1,s2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int a=helper(0,cost,dp);
        int b=helper(1,cost,dp);
        return min(a,b);
    }
};