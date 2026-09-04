class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>grt(n);
        vector<int>sml(n);
        int maxval=nums[0];
        grt[0]=maxval;
        for(int i=1;i<n;i++){
            maxval=max(maxval,nums[i]);
            grt[i]=maxval;
        }
        int minval=nums[n-1];
        sml[n-1]=minval;
        for(int i=n-1;i>=0;i--){
            minval=min(minval,nums[i]);
            sml[i]=minval;
        }
        for(int i=0;i<n;i++){
            int diff=grt[i]-sml[i];
            if(diff<=k)return i;
        }
        return -1;
    }
};