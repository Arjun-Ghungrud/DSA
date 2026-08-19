class Solution {
public: 
    void helper(int idx,vector<int>&nums,vector<vector<int>>&ans,int n,int k){
        if(nums.size()==k){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            nums.push_back(i+1);
            helper(i+1,nums,ans,n,k);
            nums.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>nums;
        helper(0,nums,ans,n,k);
        return ans;
    }
};