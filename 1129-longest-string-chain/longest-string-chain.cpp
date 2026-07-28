class Solution {
public:
    bool possible(string &s1,string &s2){
        if(s1.size() !=s2.size()+1)return false;
        int f=0;
        int s=0;
        while(f<s1.size()){
            if(s < s2.size() && s1[f]==s2[s]){
                f++;
                s++;
            }else{
                f++;
            }
        }
        if(f==s1.size() && s==s2.size())return true;
        return false;
    }
    static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int maxi=1;
        int last=0;
        sort(nums.begin(),nums.end(),comp);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(possible(nums[i],nums[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        return maxi;
    }
};