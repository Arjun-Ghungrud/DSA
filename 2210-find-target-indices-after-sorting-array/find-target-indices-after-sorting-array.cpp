class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int tar) {
        int n=nums.size();
        int count=0;
        int val=0;
        for(int i=0;i<n;i++){
            if(nums[i]<tar)count++;
            else if(nums[i]==tar)val++;
        }
        int k=0;
        vector<int>ans;
        while(k<val){
            ans.push_back(count);
            count++;
            k++;
        }
        return ans;
    }
};