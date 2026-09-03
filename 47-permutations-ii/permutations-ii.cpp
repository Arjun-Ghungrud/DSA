class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>&ans,map<vector<int>,int>&mp,vector<int>&temp,vector<bool>& used){
        if(temp.size()==nums.size()){
            if(mp.find(temp)==mp.end()){
                ans.push_back(temp);
                mp[temp]=1;
            }
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i])continue;

            temp.push_back(nums[i]);
            used[i]=true;
            helper(nums,ans,mp,temp,used);
            temp.pop_back();
            used[i]=false;
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        map<vector<int>,int>mp;
        vector<int>temp;
        vector<bool>used(n,false);
        helper(nums,ans,mp,temp,used);
        return ans;
    }
};