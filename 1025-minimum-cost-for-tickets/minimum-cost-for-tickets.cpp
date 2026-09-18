class Solution {
public:
    int helper(int i,vector<int>& days,vector<int>& costs,vector<int>&dp){
        if(i>=days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int a=costs[0]+helper(i+1,days,costs,dp);
        //7days 
        int max7=days[i]+7;
        int j1=lower_bound(days.begin(),days.end(),max7)-days.begin();
        int b=costs[1]+helper(j1,days,costs,dp);
        //30 days
        int max30=days[i]+30;
        int j2=lower_bound(days.begin(), days.end(), max30) - days.begin();
        int c=costs[2]+helper(j2,days,costs,dp);
        return dp[i]=min({a,b,c});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return helper(0,days,costs,dp);
    }
};