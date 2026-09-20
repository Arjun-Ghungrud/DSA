class Solution {
public:
    int themaxval(map<int,int>&mp){
        int maxval=INT_MIN;
        for(auto &it:mp){
            maxval=max(maxval,it.second);
        }
        return maxval;
    }
    int helper(int idx,vector<int>& cookies, int k,map<int,int>&mp){
        if(idx>=cookies.size()){
            return themaxval(mp);
        }
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            mp[i]+=cookies[idx];
            int val=helper(idx+1,cookies,k,mp);
            ans=min(ans,val);
            mp[i] -= cookies[idx];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        map<int,int>mp;
        for(int i=1;i<=k;i++){
            mp[i]=0;
        }
        return helper(0,cookies,k,mp);
    }
};