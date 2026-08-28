class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=words.size();
        vector<int>mark(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                mark[i]|=(1<<(words[i][j]-'a'));
            }
        }
        for(int i=0;i<n;i++){
            int n1=words[i].size();
            for(int j=i+1;j<n;j++){
                int n2=words[j].size();
                if((mark[i] & mark[j])==0)ans=max(ans,n1*n2);
            }
        }
        return ans;
    }
};