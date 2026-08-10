class Solution {
public:
    void helper(int i,int tar,vector<int>&v,vector<int>& nums,set<vector<int>>&ans){
        if(tar==0){
            ans.insert(v);
            return;
        }
        if(i>=nums.size() || tar<0){
            return;
        }
        if(nums[i] > tar){
            return;
        }
        v.push_back(nums[i]);
        helper(i+1,tar-nums[i],v,nums,ans);
        v.pop_back();
        int j = i + 1;
        while (j<nums.size() && nums[j]==nums[i]) { //skip duplicates 
            j++;
        }
        helper(j,tar,v,nums,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        set<vector<int>>ans;
        vector<int>v;
        sort(nums.begin(), nums.end());
        helper(0,target,v,nums,ans);
        vector<vector<int>>res;
        for (auto x : ans) {
            res.push_back(x);
        }
        return res;
    }
};