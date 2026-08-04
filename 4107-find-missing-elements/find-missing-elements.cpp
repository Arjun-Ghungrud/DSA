class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>ans;
        int a=mp.begin()->first;
        int b=mp.rbegin()->first;
        for(int i=a;i<=b;i++){
            if(mp.find(i)==mp.end())ans.push_back(i);
        }
        return ans;
    }
};