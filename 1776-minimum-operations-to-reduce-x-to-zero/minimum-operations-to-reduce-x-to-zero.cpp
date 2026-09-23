class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int tar=total-x;
        if(tar<0)return -1;
        if(tar==0)return n;
        int j=0;
        int sum=0;
        int maxl=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>tar && j<=i){
                sum-=nums[j];
                j++;
            }
            if(sum==tar){
                maxl=max(maxl,i-j+1);

            }
        }
        if(maxl==-1)return -1;
        return n-maxl;
    }
};