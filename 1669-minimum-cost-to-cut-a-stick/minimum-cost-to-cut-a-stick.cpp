class Solution {
public:
    int helper(int i,int j,vector<int> &cuts,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int id=i;id<=j;id++){
            int cost=cuts[j+1]-cuts[i-1]+helper(i,id-1,cuts,dp)+helper(id+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int c, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int n=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(c);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(1,n,cuts,dp);
    }
};