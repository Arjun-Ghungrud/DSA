class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int smallest=INT_MAX;
        vector<int>nums2(n);
        for(int i=0;i<n;i++){
            smallest=min(smallest,nums[i]);
        }
        if(smallest%2==0){
            for(int i=0;i<n;i++){
                if(nums[i]%2==0){
                    nums2[i]=nums[i];
                }else{
                    nums2[i]=nums[i]-smallest;
                }
            }
            for(int i=0;i<n;i++){
                if(nums2[i]%2!=0){
                    return false;
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(nums[i]%2!=0){
                    nums2[i]=nums[i];
                }else{
                    nums2[i]=nums[i]-smallest;
                }
            }
            for(int i=0;i<n;i++){
                if(nums2[i]%2==0){
                    return false;
                }
            }
        }
        return true;
    }
};