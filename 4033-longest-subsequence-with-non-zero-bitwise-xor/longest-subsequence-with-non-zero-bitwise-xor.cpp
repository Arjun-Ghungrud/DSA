class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        bool nonZero=false;
        for(int i=0;i<n;i++){
            res=res^nums[i];
            if(nums[i]!=0)nonZero=true;
        }
        if(!nonZero)return 0;
        return res==0 ? n-1:n;
    }
};