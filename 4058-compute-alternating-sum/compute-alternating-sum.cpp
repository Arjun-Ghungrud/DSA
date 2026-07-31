class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sumo=0;
        int sumev=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)sumev+=nums[i];
            else sumo+=nums[i];
        }
        return sumev-sumo;
    }
};