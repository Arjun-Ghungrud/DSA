class Solution {
public:
    vector<vector<int>>ans;
    void helper(int idx,vector<int>&nums,int n,int k){
        if(nums.size()==k){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            nums.push_back(i+1);
            helper(i+1,nums,n,k);
            nums.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        helper(0,nums,n,k);
        return ans;
    }
};