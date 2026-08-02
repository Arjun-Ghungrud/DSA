class Solution {
public:
    int helper(int idx,int b,int cap,vector<int>& nums,vector<vector<vector<int>>>& dp){
        if(idx>=nums.size() || cap==0)return 0;
        if(dp[idx][b][cap]!=-1)return dp[idx][b][cap];
        if(b==0){
            return dp[idx][b][cap]=max(-nums[idx]+helper(idx+1,1-b,cap,nums,dp),helper(idx+1,b,cap,nums,dp));
        }
        return dp[idx][b][cap]=max(nums[idx]+helper(idx+1,1-b,cap-1,nums,dp),helper(idx+1,b,cap,nums,dp));
    }
    int maxProfit(vector<int>& pri) {
        int n=pri.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1))
        );
        return helper(0,0,1,pri,dp);
    }
};