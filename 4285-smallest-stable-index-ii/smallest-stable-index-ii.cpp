class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>smal(n);
        int minval=nums[n-1];
        for(int i=n-1;i>=0;i--){
            minval=min(minval,nums[i]);
            smal[i]=minval;
        }
        int maxval=nums[0];
        for(int i=0;i<n;i++){
            maxval=max(maxval,nums[i]);
            int diff=maxval-smal[i];
            if(diff<=k)return i;
        }
        return -1;
    }
};