class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<long long,int>mp;
        mp[0]=1;
        long long presum=0;
        int count=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            long long rem=presum-k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[presum]++;
        }
        return count;
    }
};