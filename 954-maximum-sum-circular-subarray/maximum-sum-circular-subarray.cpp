class Solution {
public:
    int KadensMin(vector<int>& nums,int n){
        int sum=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=min(sum,ans);
            if(sum>0)sum=0;
        }
        return ans;
    }
    int KadensMax(vector<int>& nums,int n){
        int sum=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(sum,ans);
            if(sum<0)sum=0;
        }
        return ans;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxsum=KadensMax(nums,n);
        int minsum=KadensMin(nums,n);
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        int circsum=sum-minsum;
        if(maxsum>0)return max(maxsum,circsum);
        return maxsum;
    }
};