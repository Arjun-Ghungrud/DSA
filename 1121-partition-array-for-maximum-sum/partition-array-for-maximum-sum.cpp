class Solution {
public:
    // int helper(int i,int n,vector<int>& arr, int k){
    //     if(i==n)return 0;
    //     int l=0;
    //     int maxa=INT_MIN;
    //     int maxi=INT_MIN;
    //     for(int j=i;j<min(i+k,n);j++){
    //         l++;
    //         maxi=max(maxi,arr[j]);
    //         int sum=maxi*l+helper(j+1,n,arr,k);
    //         maxa=max(maxa,sum);
    //     }
    //     return maxa;
    // }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int l=0;
            int maxa=INT_MIN;
            int maxi=INT_MIN;
            for(int j=i;j<min(i+k,n);j++){
                l++;
                maxi=max(maxi,arr[j]);
                int sum=maxi*l+dp[j+1];
                maxa=max(maxa,sum);
            }
            dp[i]= maxa;
        }
        return dp[0];
    }
};