class Solution {
public:
    int sumof(int val){
        int sum=0;
        while(val>0){
            sum+=(val%10);
            val/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int s=sumof(nums[i]);
            if(s==i)return i;
        }
        return -1;
    }
};