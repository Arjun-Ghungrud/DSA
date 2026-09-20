class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int num=26-(s[i]-'a');
            ans+=(num*(i+1));
        }
        return ans;
    }
};