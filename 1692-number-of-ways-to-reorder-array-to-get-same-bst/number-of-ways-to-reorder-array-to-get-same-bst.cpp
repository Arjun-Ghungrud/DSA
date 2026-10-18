class Solution {
public:
    typedef long long ll;
    ll MOD=1e9+7;
    vector<vector<ll>>pt;
    int helper(vector<int>&nums){
        int n=nums.size();
        if(n<3)return 1;
        vector<int>l,r;
        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>root)r.push_back(nums[i]);
            else l.push_back(nums[i]);
        }
        ll x=helper(l)%MOD;
        ll y=helper(r)%MOD;
        ll z=pt[n-1][l.size()];
        return (((x*y)%MOD)*z)%MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pt.resize(n+1);
        for(int i=0;i<=n;i++){
            pt[i]=vector<ll>(i+1,1);
            for(int j=1;j<i;j++){
                pt[i][j]=(pt[i-1][j]+pt[i-1][j-1])%MOD;
            }
        }
        return helper(nums)-1;
    }
};