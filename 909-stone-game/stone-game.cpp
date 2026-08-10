class Solution {
public:
    int helper(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int picki=nums[i]+min(helper(i+2,j,nums,dp),helper(i+1,j-1,nums,dp));
        int pickj=nums[j]+min(helper(i+1,j-1,nums,dp),helper(i,j-2,nums,dp));
        return dp[i][j]=max(picki,pickj);
    }
    bool stoneGame(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int alicesum=helper(0,n-1,nums,dp);
        return alicesum>sum/2;
    }
};