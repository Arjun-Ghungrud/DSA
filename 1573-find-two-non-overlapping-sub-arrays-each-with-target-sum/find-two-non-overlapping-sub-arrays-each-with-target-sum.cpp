class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n=nums.size();
        int j=0;
        int curr=0;
        vector<int>minBest(n,INT_MAX);
        int bestMin=INT_MAX;
        int res=INT_MAX;

        for(int i=0;i<n;i++){
            curr+=nums[i];
            while(curr>target && j<=i){
                curr-=nums[j];
                j++;
            }
            if(curr==target){
                int len=i-j+1;
                if(j>0 && minBest[j-1]!=INT_MAX){
                    res=min(res,len+minBest[j-1]);
                }
                bestMin=min(bestMin,len);
            }
            minBest[i]=bestMin;
        }
        return res==INT_MAX?-1:res;
    }
};