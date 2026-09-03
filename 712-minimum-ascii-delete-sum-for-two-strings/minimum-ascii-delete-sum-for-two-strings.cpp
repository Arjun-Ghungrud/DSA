class Solution {
public:
    int helper(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i>=s1.size() && j>=s2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i>=s1.size())return dp[i][j]=s2[j]+helper(i,j+1,s1,s2,dp);
        if(j>=s2.size())return dp[i][j]=s1[i]+helper(i+1,j,s1,s2,dp);
        if(s1[i]==s2[j])return dp[i][j]=helper(i+1,j+1,s1,s2,dp);
        int m1=s1[i]+helper(i+1,j,s1,s2,dp);
        int m2=s2[j]+helper(i,j+1,s1,s2,dp);
        return dp[i][j]=min(m1,m2);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,s1,s2,dp);
    }
};