class Solution {
public:
    int helper(int idx,int b,vector<int>& nums,vector<vector<int>>&dp){
        if(idx>=nums.size())return 0;
        if(dp[idx][b]!=-1)return dp[idx][b];
        if(b==0){
            return dp[idx][b]=max(-nums[idx]+helper(idx+1,1-b,nums,dp),helper(idx+1,b,nums,dp));
        }
        return dp[idx][b]=max(nums[idx]+helper(idx+1,1-b,nums,dp),helper(idx+1,b,nums,dp));
    }
    int maxProfit(vector<int>& pri) {
        int n=pri.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(0,0,pri,dp);
    }
};  