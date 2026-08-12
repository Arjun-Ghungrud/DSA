class Solution {
public:
    int helper(int i,int j,vector<int>&nums){
        if(i>j)return 0;
        int a=nums[i]+min(helper(i+2,j,nums),helper(i+1,j-1,nums));
        int b=nums[j]+min(helper(i,j-2,nums),helper(i+1,j-1,nums));
        return max(a,b);
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int p1=helper(0,n-1,nums);
        int p2=sum-p1;
        return p1>=p2;
    }
};