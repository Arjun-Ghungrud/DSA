class Solution {
public:
    bool palindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    // int helper(int i,int n,string &s){
    //     if(i==n)return 0;
    //     int minc=INT_MAX;
    //     for(int j=i;j<n;j++){
    //         if(palindrome(i,j,s)){
    //             int cost=1+helper(j+1,n,s);
    //             minc=min(minc,cost);
    //         }
    //     }
    //     return minc;
    // }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int minc=INT_MAX;
            for(int j=i;j<n;j++){
                if(palindrome(i,j,s)){
                    int cost=1+dp[j+1];
                    minc=min(minc,cost);
                }
            }
            dp[i]= minc;
        }
        return dp[0]-1;
    }
};