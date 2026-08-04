class Solution {
public:
    static bool cmp(vector<int>v1,vector<int>v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int n=inter.size();
        sort(inter.begin(),inter.end(),cmp);
        int lastend=inter[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(lastend>inter[i][0]){
                count++;
            }
            else lastend=inter[i][1];
        }
        return count;
    }
};