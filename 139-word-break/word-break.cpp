class Solution {
public:
    bool helper(int idx,string &s,unordered_set<string>& mp,vector<int>&dp){
        if(idx>=s.size())return true;
        if(dp[idx]!=-1)return dp[idx];
        for(int i=1;idx+i<=s.size();i++){
            string temp=s.substr(idx,i);
            if(mp.find(temp)!=mp.end() && helper(idx+i,s,mp,dp))return dp[idx]=1;
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, -1);
        return helper(0, s, dict, dp);
    }
};