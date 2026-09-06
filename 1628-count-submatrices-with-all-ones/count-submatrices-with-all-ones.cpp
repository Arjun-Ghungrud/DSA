class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>h(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)h[j]+=1;
                else h[j]=0;
            }
            for(int j=0;j<m;j++){
                if(h[j]==0)continue;
                int val=h[j];
                for(int k=j;k>=0;k--){
                    val=min(val,h[k]);
                    ans+=val;
                }
            }
        }
        return ans;
    }
};