class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buyP=INT_MAX;
        int maxPro=0;
        for(int i=1;i<n;i++){
            buyP=min(buyP,prices[i-1]);
            maxPro=max(maxPro,prices[i]-buyP);
        }
        return maxPro;
    }
};