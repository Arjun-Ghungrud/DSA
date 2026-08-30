class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minele=INT_MAX;
        int minidx=0;
        int maxele=INT_MIN;
        int maxidx=0;
        for(int i=0;i<n;i++){
            if(minele>nums[i]){
                minele=nums[i];
                minidx=i;
            }
        }
        for(int i=0;i<n;i++){
            if(maxele<nums[i]){
                maxele=nums[i];
                maxidx=i;
            }
        }
        int forward=max(maxidx,minidx)+1;
        int back=(n-min(maxidx,minidx));
        int rfor=min(maxidx,minidx)+1;
        int rback=(n-max(maxidx,minidx));
        int opt=rfor+rback;
        int val=min(forward,back);
        int ans=min(opt,val);
        return ans;
    }
};